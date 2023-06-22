#include <combo.h>
#include <combo/item.h>

#define SET_HANDLER(a, h) do { *(void**)(((char*)(a)) + 0x144) = (h); } while (0)

// maybe worth moving somewhere common
static void FreezePlayer(GameState_Play* play) {
    Actor_Player* link;
    link = GET_LINK(play);
    link->base.freezeTimer = 100;
    link->state |= PLAYER_ACTOR_STATE_FROZEN;
}

// maybe worth moving somewhere common
static void UnfreezePlayer(GameState_Play* play) {
    Actor_Player* link;
    link = GET_LINK(play);
    link->base.freezeTimer = 0;
    link->state &= ~PLAYER_ACTOR_STATE_FROZEN;
}

void EnSi_WaitForPlayerToCloseMessage(Actor* this, GameState_Play* play) {
    if (Message_IsClosed(this, play)) {
        UnfreezePlayer(play);
        ActorDestroy(this);
    } else {
        FreezePlayer(play);
    }
}

static void EnSi_ItemQuery(ComboItemQuery* q, Actor* this, GameState_Play* play, int flags)
{
    bzero(q, sizeof(*q));
    q->ovType = OV_CHEST;
    q->sceneId = play->sceneId;
    q->id = (this->variable & 0xfc) >> 2;
    q->gi = play->sceneId == SCE_MM_SPIDER_HOUSE_OCEAN ? GI_MM_GS_TOKEN_OCEAN : GI_MM_GS_TOKEN_SWAMP;
    q->ovFlags = flags;
}

static void EnSi_ItemOverride(ComboItemOverride* o, Actor* this, GameState_Play* play, int flags)
{
    ComboItemQuery q;

    EnSi_ItemQuery(&q, this, play, flags);
    comboItemOverride(o, &q);
}

void EnSi_AddItem(Actor* this, GameState_Play* play)
{
    ComboItemQuery q;

    EnSi_ItemQuery(&q, this, play, OVF_PROGRESSIVE | OVF_DOWNGRADE);
    SetChestFlag(play, (this->variable & 0xfc) >> 2);
    PlayerDisplayTextBox(play, 0x52, NULL);
    comboAddItemEx(play, &q);
    PlaySoundSpecial(0x39);
    FreezePlayer(play);
    SET_HANDLER(this, EnSi_WaitForPlayerToCloseMessage);
    this->draw = NULL;
}

PATCH_FUNC(0x8098cad0, EnSi_AddItem);

void EnSi_Draw(Actor* this, GameState_Play* play)
{
    ComboItemOverride o;

    EnSi_ItemOverride(&o, this, play, OVF_PROGRESSIVE);
    comboDrawGI(play, this, o.gi, 0);
}

PATCH_FUNC(0x8098cd0c, EnSi_Draw);
