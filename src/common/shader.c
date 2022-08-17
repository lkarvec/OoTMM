#include <combo.h>

void Shader_Opa0_Xlu1(void*, s16);
void Shader_Opa0_Xlu12(void*, s16);
void Shader_Opa0(void*, s16);
void Shader_Opa01(void*, s16);
void Shader_Opa0123(void*, s16);
void Shader_Opa10_Xlu2(void*, s16);
void Shader_Opa10_Xlu234(void*, s16);
void Shader_Opa10_Xlu32(void*, s16);
void Shader_Opa10234567(void*, s16);
void Shader_Xlu01(void*, s16);
void Shader_BlueFire(void*, s16);
void Shader_BombchuMask(void*, s16);
void Shader_Compass(void*, s16);
void Shader_DekuNut(void*, s16);
void Shader_Fairy(void*, s16);
void Shader_Fish(void*, s16);
void Shader_GiantKnife(void*, s16);
void Shader_GS(void*, s16);
void Shader_Heart(void*, s16);
void Shader_Medallion(void*, s16);
void Shader_MirrorShield(void*, s16);
void Shader_Poe(void*, s16);
void Shader_Potion(void*, s16);
void Shader_Rupee(void*, s16);
void Shader_Scale(void*, s16);
void Shader_SoldOut(void*, s16);
void Shader_Spell(void*, s16);

const Shader kShaders[256] = {
#if defined(GAME_OOT)
# include "data/oot/shaders.inc"
# include "data/mm/shaders.inc"
#endif
};

void comboInitShaders(void)
{
}