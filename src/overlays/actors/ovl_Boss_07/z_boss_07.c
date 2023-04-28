/*
 * File: z_boss_07.c
 * Overlay: ovl_Boss_07
 * Description: Majora
 */

#include "z_boss_07.h"
#include "z64shrink_window.h"

#define FLAGS (ACTOR_FLAG_1 | ACTOR_FLAG_4 | ACTOR_FLAG_10 | ACTOR_FLAG_20)

#define THIS ((Boss07*)thisx)

void Boss07_Init(Actor* thisx, PlayState* play);
void Boss07_Destroy(Actor* thisx, PlayState* play);
void Boss07_Update(Actor* thisx, PlayState* play);
void Boss07_Draw(Actor* thisx, PlayState* play);

void func_8019FE1C(Vec3f * vec, s32 arg1, s32 arg2);
void func_809F4CBC(Boss07 * this, f32 maxStep);   
void func_809F4D10(Vec3f* arg0, f32 arg1);
void func_809F5E88(Boss07* this, PlayState* play);
void func_809F65F4(Boss07* this, PlayState* play);
void func_809F7400(Boss07 *this, PlayState *play, s16 arg2);
void func_809F748C(Boss07* this, PlayState* play);
void func_809F76D0(Boss07* this, PlayState* play);
void func_809F77A8(Boss07* this, PlayState* play);
void func_809F7968(Boss07* this, PlayState* play);
void func_809F7BC4(Boss07* this, PlayState* play);
void func_809F7D2C(Boss07* this, PlayState* play);
void func_809F805C(Boss07* this, PlayState* play);
void func_809F86B8(Boss07* this, PlayState* play);
void func_809F87C8(Boss07* this, PlayState* play);
void func_809F8908(Boss07* this, PlayState* play);
void func_809F8B1C(Boss07* this, PlayState* play);
void func_809F8D04(Boss07* this, PlayState* play);
void func_809F8EC8(Boss07* this, PlayState* play);
void func_809F91D4(Boss07* this, PlayState* play);
void func_809FCCCC(Boss07* this, PlayState* play);
void func_809FD710(Boss07* this, PlayState* play);
void func_809FD89C(Boss07* this, PlayState* play);
void func_809FDAB0(Boss07* this, PlayState* play);
void func_809FDF54(Boss07* this, PlayState* play);
void func_809FE0E4(Boss07* this, PlayState* play);
void func_809FE348(Boss07* this, PlayState* play);
void func_809FE524(Boss07* this, PlayState* play);
void func_809FE734(Boss07* this, PlayState* play);
void func_809FFA80(Boss07* this, PlayState* play);
void func_809FFEAC(Boss07* this, PlayState* play);
void func_80A00274(Boss07* this, PlayState* play);
void func_80A00554(Boss07* this, PlayState* play);
void func_80A00720(Boss07* this, PlayState* play);
void func_80A01750(Boss07* this, PlayState* play);
void func_80A0264C(Boss07* this, PlayState* play);
void func_80A04890(Boss07* this, PlayState* play);
void func_80A04E5C(Boss07* this, PlayState* play);
void func_80A05608(Boss07* this, PlayState* play);
void func_80A05694(Boss07* this, PlayState* play);
void func_80A05B50(Boss07* this, PlayState* play);
void func_80A05DDC(Boss07* this, PlayState* play);

#if 0
// static DamageTable sDamageTable = {
static DamageTable D_80A07980 = {
    /* Deku Nut       */ DMG_ENTRY(0, 0x0),
    /* Deku Stick     */ DMG_ENTRY(1, 0xF),
    /* Horse trample  */ DMG_ENTRY(0, 0x0),
    /* Explosives     */ DMG_ENTRY(2, 0xF),
    /* Zora boomerang */ DMG_ENTRY(1, 0xF),
    /* Normal arrow   */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x06   */ DMG_ENTRY(0, 0x0),
    /* Hookshot       */ DMG_ENTRY(0, 0x0),
    /* Goron punch    */ DMG_ENTRY(1, 0xF),
    /* Sword          */ DMG_ENTRY(1, 0xF),
    /* Goron pound    */ DMG_ENTRY(1, 0xF),
    /* Fire arrow     */ DMG_ENTRY(2, 0x2),
    /* Ice arrow      */ DMG_ENTRY(2, 0x3),
    /* Light arrow    */ DMG_ENTRY(2, 0x4),
    /* Goron spikes   */ DMG_ENTRY(1, 0xF),
    /* Deku spin      */ DMG_ENTRY(1, 0xF),
    /* Deku bubble    */ DMG_ENTRY(1, 0xF),
    /* Deku launch    */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x12   */ DMG_ENTRY(0, 0x0),
    /* Zora barrier   */ DMG_ENTRY(0, 0x0),
    /* Normal shield  */ DMG_ENTRY(0, 0x0),
    /* Light ray      */ DMG_ENTRY(0, 0x0),
    /* Thrown object  */ DMG_ENTRY(1, 0xF),
    /* Zora punch     */ DMG_ENTRY(1, 0xF),
    /* Spin attack    */ DMG_ENTRY(2, 0xF),
    /* Sword beam     */ DMG_ENTRY(2, 0x9),
    /* Normal Roll    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(0, 0x0),
    /* Unblockable    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(0, 0x0),
    /* Powder Keg     */ DMG_ENTRY(2, 0xF),
};

// static DamageTable sDamageTable = {
static DamageTable D_80A079A0 = {
    /* Deku Nut       */ DMG_ENTRY(0, 0x0),
    /* Deku Stick     */ DMG_ENTRY(1, 0xF),
    /* Horse trample  */ DMG_ENTRY(0, 0x0),
    /* Explosives     */ DMG_ENTRY(1, 0xC),
    /* Zora boomerang */ DMG_ENTRY(1, 0xF),
    /* Normal arrow   */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x06   */ DMG_ENTRY(0, 0x0),
    /* Hookshot       */ DMG_ENTRY(0, 0x0),
    /* Goron punch    */ DMG_ENTRY(1, 0xE),
    /* Sword          */ DMG_ENTRY(1, 0xE),
    /* Goron pound    */ DMG_ENTRY(1, 0xF),
    /* Fire arrow     */ DMG_ENTRY(2, 0x2),
    /* Ice arrow      */ DMG_ENTRY(2, 0x3),
    /* Light arrow    */ DMG_ENTRY(2, 0x4),
    /* Goron spikes   */ DMG_ENTRY(1, 0xF),
    /* Deku spin      */ DMG_ENTRY(1, 0xF),
    /* Deku bubble    */ DMG_ENTRY(1, 0xF),
    /* Deku launch    */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x12   */ DMG_ENTRY(0, 0x0),
    /* Zora barrier   */ DMG_ENTRY(0, 0xA),
    /* Normal shield  */ DMG_ENTRY(0, 0x0),
    /* Light ray      */ DMG_ENTRY(0, 0x0),
    /* Thrown object  */ DMG_ENTRY(1, 0xF),
    /* Zora punch     */ DMG_ENTRY(1, 0xF),
    /* Spin attack    */ DMG_ENTRY(1, 0xD),
    /* Sword beam     */ DMG_ENTRY(2, 0x9),
    /* Normal Roll    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(0, 0x0),
    /* Unblockable    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(0, 0x0),
    /* Powder Keg     */ DMG_ENTRY(4, 0xC),
};

// static DamageTable sDamageTable = {
static DamageTable D_80A079C0 = {
    /* Deku Nut       */ DMG_ENTRY(0, 0x0),
    /* Deku Stick     */ DMG_ENTRY(1, 0xE),
    /* Horse trample  */ DMG_ENTRY(0, 0x0),
    /* Explosives     */ DMG_ENTRY(1, 0xC),
    /* Zora boomerang */ DMG_ENTRY(1, 0xF),
    /* Normal arrow   */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x06   */ DMG_ENTRY(0, 0x0),
    /* Hookshot       */ DMG_ENTRY(0, 0x0),
    /* Goron punch    */ DMG_ENTRY(1, 0xE),
    /* Sword          */ DMG_ENTRY(1, 0xE),
    /* Goron pound    */ DMG_ENTRY(1, 0xF),
    /* Fire arrow     */ DMG_ENTRY(2, 0x2),
    /* Ice arrow      */ DMG_ENTRY(2, 0x3),
    /* Light arrow    */ DMG_ENTRY(2, 0x4),
    /* Goron spikes   */ DMG_ENTRY(1, 0xE),
    /* Deku spin      */ DMG_ENTRY(1, 0xE),
    /* Deku bubble    */ DMG_ENTRY(1, 0xF),
    /* Deku launch    */ DMG_ENTRY(1, 0xE),
    /* UNK_DMG_0x12   */ DMG_ENTRY(0, 0x0),
    /* Zora barrier   */ DMG_ENTRY(0, 0xA),
    /* Normal shield  */ DMG_ENTRY(0, 0x0),
    /* Light ray      */ DMG_ENTRY(0, 0x0),
    /* Thrown object  */ DMG_ENTRY(1, 0xF),
    /* Zora punch     */ DMG_ENTRY(1, 0xE),
    /* Spin attack    */ DMG_ENTRY(1, 0xD),
    /* Sword beam     */ DMG_ENTRY(2, 0x9),
    /* Normal Roll    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(0, 0x0),
    /* Unblockable    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(0, 0x0),
    /* Powder Keg     */ DMG_ENTRY(2, 0xC),
};

// static DamageTable sDamageTable = {
static DamageTable D_80A079E0 = {
    /* Deku Nut       */ DMG_ENTRY(0, 0x0),
    /* Deku Stick     */ DMG_ENTRY(1, 0xF),
    /* Horse trample  */ DMG_ENTRY(0, 0x0),
    /* Explosives     */ DMG_ENTRY(2, 0xE),
    /* Zora boomerang */ DMG_ENTRY(1, 0xF),
    /* Normal arrow   */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x06   */ DMG_ENTRY(0, 0x0),
    /* Hookshot       */ DMG_ENTRY(0, 0x0),
    /* Goron punch    */ DMG_ENTRY(1, 0xE),
    /* Sword          */ DMG_ENTRY(1, 0xE),
    /* Goron pound    */ DMG_ENTRY(1, 0xF),
    /* Fire arrow     */ DMG_ENTRY(2, 0x2),
    /* Ice arrow      */ DMG_ENTRY(2, 0x3),
    /* Light arrow    */ DMG_ENTRY(2, 0x4),
    /* Goron spikes   */ DMG_ENTRY(1, 0xF),
    /* Deku spin      */ DMG_ENTRY(1, 0xF),
    /* Deku bubble    */ DMG_ENTRY(1, 0xF),
    /* Deku launch    */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x12   */ DMG_ENTRY(0, 0x0),
    /* Zora barrier   */ DMG_ENTRY(0, 0x0),
    /* Normal shield  */ DMG_ENTRY(0, 0x0),
    /* Light ray      */ DMG_ENTRY(0, 0x0),
    /* Thrown object  */ DMG_ENTRY(1, 0xF),
    /* Zora punch     */ DMG_ENTRY(1, 0xF),
    /* Spin attack    */ DMG_ENTRY(1, 0xD),
    /* Sword beam     */ DMG_ENTRY(2, 0x9),
    /* Normal Roll    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(0, 0x0),
    /* Unblockable    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(0, 0x0),
    /* Powder Keg     */ DMG_ENTRY(2, 0xE),
};

// static DamageTable sDamageTable = {
static DamageTable D_80A07A00 = {
    /* Deku Nut       */ DMG_ENTRY(0, 0x0),
    /* Deku Stick     */ DMG_ENTRY(1, 0xD),
    /* Horse trample  */ DMG_ENTRY(1, 0xE),
    /* Explosives     */ DMG_ENTRY(1, 0xB),
    /* Zora boomerang */ DMG_ENTRY(1, 0xF),
    /* Normal arrow   */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x06   */ DMG_ENTRY(0, 0x0),
    /* Hookshot       */ DMG_ENTRY(1, 0xE),
    /* Goron punch    */ DMG_ENTRY(1, 0xE),
    /* Sword          */ DMG_ENTRY(1, 0xD),
    /* Goron pound    */ DMG_ENTRY(0, 0x0),
    /* Fire arrow     */ DMG_ENTRY(1, 0xE),
    /* Ice arrow      */ DMG_ENTRY(1, 0xE),
    /* Light arrow    */ DMG_ENTRY(1, 0xE),
    /* Goron spikes   */ DMG_ENTRY(1, 0xC),
    /* Deku spin      */ DMG_ENTRY(1, 0xF),
    /* Deku bubble    */ DMG_ENTRY(1, 0xF),
    /* Deku launch    */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x12   */ DMG_ENTRY(0, 0x0),
    /* Zora barrier   */ DMG_ENTRY(0, 0x0),
    /* Normal shield  */ DMG_ENTRY(1, 0xD),
    /* Light ray      */ DMG_ENTRY(1, 0xD),
    /* Thrown object  */ DMG_ENTRY(1, 0xE),
    /* Zora punch     */ DMG_ENTRY(1, 0xE),
    /* Spin attack    */ DMG_ENTRY(1, 0xA),
    /* Sword beam     */ DMG_ENTRY(1, 0xA),
    /* Normal Roll    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(0, 0x0),
    /* Unblockable    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(0, 0x0),
    /* Powder Keg     */ DMG_ENTRY(2, 0xB),
};

ActorInit Boss_07_InitVars = {
    ACTOR_BOSS_07,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_BOSS07,
    sizeof(Boss07),
    (ActorFunc)Boss07_Init,
    (ActorFunc)Boss07_Destroy,
    (ActorFunc)Boss07_Update,
    (ActorFunc)Boss07_Draw,
};

// static ColliderJntSphElementInit sJntSphElementsInit[11] = {
static ColliderJntSphElementInit D_80A07A40[11] = {
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 0, { { 0, 0, 0 }, 20 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 30 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 25 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 150 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 150 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 150 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 150 },
    },
};

// static ColliderJntSphInit sJntSphInit = {
static ColliderJntSphInit D_80A07BCC = {
    { COLTYPE_HIT3, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_PLAYER, OC2_TYPE_1, COLSHAPE_JNTSPH, },
    ARRAY_COUNT(sJntSphElementsInit), D_80A07A40, // sJntSphElementsInit,
};

// static ColliderCylinderInit sCylinderInit = {
static ColliderCylinderInit D_80A07BDC = {
    { COLTYPE_METAL, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_1, COLSHAPE_CYLINDER, },
    { ELEMTYPE_UNK2, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
    { 80, 200, 0, { 0, 0, 0 } },
};

// static ColliderJntSphElementInit sJntSphElementsInit[1] = {
static ColliderJntSphElementInit D_80A07C08[1] = {
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_HARD, BUMP_ON, OCELEM_ON, },
        { 0, { { 0, 0, 0 }, 36 }, 200 },
    },
};

// static ColliderJntSphInit sJntSphInit = {
static ColliderJntSphInit D_80A07C2C = {
    { COLTYPE_HIT3, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_PLAYER, OC2_TYPE_1, COLSHAPE_JNTSPH, },
    ARRAY_COUNT(sJntSphElementsInit), D_80A07C08, // sJntSphElementsInit,
};

// static ColliderQuadInit sQuadInit = {
static ColliderQuadInit D_80A07C3C = {
    { COLTYPE_METAL, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_HARD | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_1, COLSHAPE_QUAD, },
    { ELEMTYPE_UNK2, { 0xF7CFFFFF, 0x04, 0x00 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

// static ColliderQuadInit sQuadInit = {
static ColliderQuadInit D_80A07C8C = {
    { COLTYPE_HIT3, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_1, COLSHAPE_QUAD, },
    { ELEMTYPE_UNK2, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

// static ColliderJntSphElementInit sJntSphElementsInit[11] = {
static ColliderJntSphElementInit D_80A07CDC[11] = {
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 0, { { 0, 0, 0 }, 25 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 40 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 0 }, 0 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 150 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 150 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 150 },
    },
    {
        { ELEMTYPE_UNK3, { 0xF7CFFFFF, 0x00, 0x10 }, { 0xF7CEFFFE, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 1, { { 0, 0, 0 }, 15 }, 150 },
    },
};

// static ColliderJntSphInit sJntSphInit = {
static ColliderJntSphInit D_80A07E68 = {
    { COLTYPE_HIT3, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_PLAYER, OC2_TYPE_1, COLSHAPE_JNTSPH, },
    ARRAY_COUNT(sJntSphElementsInit), D_80A07CDC, // sJntSphElementsInit,
};

// static ColliderCylinderInit sCylinderInit = {
static ColliderCylinderInit D_80A07E78 = {
    { COLTYPE_NONE, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_1, COLSHAPE_CYLINDER, },
    { ELEMTYPE_UNK0, { 0xF7CFFFFF, 0x04, 0x10 }, { 0x00300000, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
    { 15, 30, -15, { 0, 0, 0 } },
};

// static ColliderCylinderInit sCylinderInit = {
static ColliderCylinderInit D_80A07EA4 = {
    { COLTYPE_METAL, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_1, COLSHAPE_CYLINDER, },
    { ELEMTYPE_UNK0, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON | BUMP_HOOKABLE, OCELEM_ON, },
    { 50, 100, -50, { 0, 0, 0 } },
};

// static ColliderCylinderInit sCylinderInit = {
static ColliderCylinderInit D_80A07ED0 = {
    { COLTYPE_METAL, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_HARD | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_1, COLSHAPE_CYLINDER, },
    { ELEMTYPE_UNK0, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7FFFFFF, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON | BUMP_HOOKABLE, OCELEM_ON, },
    { 40, 20, 15, { 0, 0, 0 } },
};

static s16 D_80A07F54[4] = { 0xC8, 0xC9, 0xCA, 0xCB };

static Vec3f D_80A07F6C[5] = {
    { 40.0f, 400.0f, 110.0f },
    { 80.0f, 450.0f, 110.0f },
    { 100.0f, 400.0f, 110.0f },
    { 60.0f, 390.0f, 110.0f },
    { 30.0f, 430.0f, 110.0f },
};

#endif

extern DamageTable D_80A07980;
extern DamageTable D_80A079A0;
extern DamageTable D_80A079C0;
extern DamageTable D_80A079E0;
extern DamageTable D_80A07A00;
extern ColliderJntSphElementInit D_80A07A40[11];
extern ColliderJntSphInit D_80A07BCC;
extern ColliderCylinderInit D_80A07BDC;
extern ColliderJntSphElementInit D_80A07C08[1];
extern ColliderJntSphInit D_80A07C2C;
extern ColliderQuadInit D_80A07C3C;
extern ColliderQuadInit D_80A07C8C;
extern ColliderJntSphElementInit D_80A07CDC[11];
extern ColliderJntSphInit D_80A07E68;
extern ColliderCylinderInit D_80A07E78;
extern ColliderCylinderInit D_80A07EA4;
extern ColliderCylinderInit D_80A07ED0;
extern Vec3f D_80A07F6C[5];
extern Vec3f D_80A09A40;
extern s8 D_80A09A4C;
extern s32 D_80A09A50;
extern Boss07 *D_80A09A54;
extern Boss07 *D_80A09A58;
extern Boss07 *D_80A09A5C;
extern Boss07 *D_80A09A60[4];
extern s8 D_80A09A70;
extern s8 D_80A09A71;
extern UNK_TYPE D_80A09A78;
extern UNK_TYPE D_80A0A888;
// static struct _struct_D_80A07F3C_0x6 D_80A07F3C[4]; // Vec3s?
extern s16 D_80A07F54[4];
extern UNK_TYPE D_80A07F5C;                                /* unable to generate initializer */
extern UNK_TYPE D_80A07F64;

extern UNK_TYPE D_06000194;
extern UNK_TYPE D_06000428;
extern UNK_TYPE D_06000D0C;
extern UNK_TYPE D_06002C40;
extern UNK_TYPE D_06002D84;
extern UNK_TYPE D_06003854;
extern UNK_TYPE D_06003A64;
extern FlexSkeletonHeader D_060099A0;
extern UNK_TYPE D_06009C7C;
extern UNK_TYPE D_06009EA8;
extern UNK_TYPE D_0600A194;
extern UNK_TYPE D_0600A400;
extern AnimationHeader D_0600A6AC;
extern UNK_TYPE D_0600AE40;
extern UNK_TYPE D_0600AFB0;
extern UNK_TYPE D_0600B020;
extern UNK_TYPE D_0600C7D8;
extern UNK_TYPE D_0600CEE8;
extern UNK_TYPE D_060149A0;
extern SkeletonHeader D_06019C58;
extern UNK_TYPE D_06019E48;
extern UNK_TYPE D_0601DEB4;
extern UNK_TYPE D_06022BB4;
extern AnimationHeader D_06023DAC;
extern UNK_TYPE D_06025018;
extern UNK_TYPE D_06025878;
extern AnimationHeader D_06026204;
extern UNK_TYPE D_060269EC;
extern UNK_TYPE D_06026EA0;
extern UNK_TYPE D_06027270;
extern UNK_TYPE D_0602EEC8;
extern UNK_TYPE D_0602EF68;
extern UNK_TYPE D_0602EFE8;
extern UNK_TYPE D_0602F640;
extern UNK_TYPE D_0602F840;
extern void* D_06032040;
extern FlexSkeletonHeader D_060335F0;
extern AnimationHeader D_06033F80;
extern AnimationHeader D_06034E64;
extern AnimationHeader D_060358C4;
extern AnimationHeader D_06036A7C;
extern AnimationHeader D_06037ADC;
extern AnimationHeader D_0603918C;
extern UNK_TYPE D_0603B330;
extern AnimationHeader D_0603C4E0;
extern AnimationHeader D_0603CBD0;
extern UNK_TYPE D_0603D7F0;
extern UNK_TYPE D_0603DD1C;
extern UNK_TYPE D_06040930;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F4980.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F49A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F49C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F4AE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F4BB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F4C40.s")

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F4CBC.s")

/** Decelerates actor by at most maxStep, or stops if colliding with a wall or ceiling */
void func_809F4CBC(Boss07* this, f32 maxStep) {
    Math_ApproachZeroF(&this->actor.speed, 1.0f, maxStep);
    if (this->actor.bgCheckFlags & (BGCHECKFLAG_WALL | BGCHECKFLAG_CEILING)) {
        this->actor.speed = 0.0f;
    }
}

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F4D10.s")
void func_809F4D10(Vec3f* arg0, f32 arg1) {
    Matrix_RotateYF(Rand_ZeroFloat(M_PI * 2), MTXMODE_NEW);
    Matrix_MultVecZ(arg1, arg0);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F4D54.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F4FAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F4FF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F51E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F52CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F536C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F5494.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/Boss07_Init.s")

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/Boss07_Destroy.s")
void Boss07_Destroy(Actor *thisx, PlayState *play) {
    Boss07 *this = THIS;

    switch (this->actor.params) {
        case 0x1E:
            Collider_DestroyQuad(play, &this->unk18F0);
            Collider_DestroyQuad(play, &this->unk1970);
        case 0xB4:
            Effect_Destroy(play, this->unk18DC);
            return;
    }
}

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F5E14.s")
void func_809F5E14(Boss07 *this, PlayState *play) {
    this->actionFunc = func_809F5E88;
    Animation_MorphToLoop(&this->skelAnime, &D_06023DAC, 0.0f);
    this->actor.flags &= ~1;
    this->unk17D8 = 0x7F00;
    this->unk15C = 0x14;
    this->unk17E8 = 5120.0f;
}

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F5E88.s")
void func_809F5E88(Boss07 *this, PlayState *play) {
    Player* player;
    u32 i;
    u32 index;
    Camera *camera;

    this->unk15C = 0x14;
    SkelAnime_Update(&this->skelAnime);
    this->unkABC8++;
    Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, MTXMODE_NEW);
    Matrix_RotateYS(this->actor.shape.rot.y, MTXMODE_APPLY);

    switch(this->unkABD0) {
        case 0:
            this->unkABC8 = 0;
            this->unkABD0 = 1;
            this->unkABF8.z = 0.0f;
            this->unkABEC.x = 0.0f;
            this->unkABEC.y = (((f32) KREG(17) + 100.0f) - 30.0f) + 80.0f;
            this->unkABEC.z = ((((f32) KREG(18) + 270.0f) - 150.0f) + 30.0f) - 50.0f;
            this->unkABF8.x = 0.0f;
            this->unkABF8.y = 180.0f;
        case 1:
            if (this->unkABC8 < 0x28U) {
                D_80A09A4C = 3;
            }
            if (this->unkABC8 >= 0x15U) {
                if (this->unkABC8 == 0x15) {
                    Actor_PlaySfx(&this->actor, 0x39BBU);
                }
                Math_ApproachS(&this->unk17D8, 0, 5, 0x1000);
                this->unk17DA = (s16) (Math_SinS((this->unkABC8 << 0xC)) * this->unk17E8);
                this->unk17DC = (s16) (Math_SinS((this->unkABC8 * 0xB00)) * this->unk17E8 * 0.5f);
                if (this->unkABC8 >= 0x29U) {
                    Math_ApproachZeroF(&this->unk17E8, 1.0f, 200.0f);
                }
            }
            if (this->unkABC8 >= 0x3DU) {
                index = 0;
                player = GET_PLAYER(play);
                if (player->transformation == 1) {
                    index = 1;
                } else if (player->transformation == 0) {
                    index = 2;
                } else if (player->transformation == 2) {
                    index = 3;
                } else if (player->transformation == 3) {
                    index = 4;
                }
                Math_ApproachF(&this->unkABEC.y, D_80A07F6C[index].x, 0.075f, this->unkAC0C * 7.0f);
                Math_ApproachF(&this->unkABEC.z, D_80A07F6C[index].y, 0.075f, this->unkAC0C * 17.0f);
                Math_ApproachF(&this->unkABF8.y, D_80A07F6C[index].z, 0.075f, this->unkAC0C * 7.0f);
                Math_ApproachF(&this->unkAC0C, 1.0f, 1.0f, 0.01f);
                if (this->unkABC8 == 0x46) {
                    Animation_MorphToPlayOnce(&this->skelAnime, (AnimationHeader *) &D_06025018, -15.0f);
                    this->unk1D4 = (f32) Animation_GetLastFrame(&D_06025018);
                    func_8019FE1C(&this->actor.projectedPos, 0x290D, 0x3F800000);
                    Actor_PlaySfx(&this->actor, 0x39B9U);
                }
                if (this->unkABC8 >= 0x6EU) {
                    Math_ApproachF(&this->unk77C, 1.0f, 1.0f, 0.05f);
                    this->unk794 = 0.79999995f;
                    this->unkFA0 = 0.79999995f;
                    this->unk798 = 1.0f;
                    this->unkFA4 = 1.0f;
                }
                if (this->unkABC8 == 0x7F) {
                    this->unk77C = 1.0f;
                }
                if (this->unkABC8 == 0x78) {
                    Actor_PlaySfx(&this->actor, 0x39CEU);
                    Audio_PlaySfxAtPos(&D_80A09A40, 0x3A53U);
                    func_8019FE74(&gSfxVolume, 0.0f, 0x3C);
                }
                if (this->unkABC8 == 0x70) {
                    AudioSeq_QueueSeqCmd(0x8069U);
                }
                if (this->unkABC8 == 0x89) {
                    TitleCard_InitBossName(&play->state, &play->actorCtx.titleCtxt, Lib_SegmentedToVirtual(&D_06032040), 0xA0, 0xB4, 0x80, 0x28);
                }
                if (Animation_OnFrame(&this->skelAnime, this->unk1D4) != 0) {
                    camera = Play_GetCamera(play, 0);
                    this->unkABD0 = 0;
                    func_809F7400(this, play, 0x32);
                    camera->eye = this->unkABD4;
                    camera->eyeNext = this->unkABD4;
                    camera->at = this->unkABE0;
                    func_80169AFC(play, this->unkABD2, 0);
                    this->unkABD2 = 0;
                    Cutscene_StopManual(play, &play->csCtx);
                    func_800B7298(play, &this->actor, 6);
                    this->actor.flags |= 1;
                    Play_DisableMotionBlur();
                    if (D_80A09A60[0] != NULL) {
                        for(i = 0; i < ARRAY_COUNT(D_80A09A60); i++) {
                            func_800BC154(play, &play->actorCtx, (Actor *)D_80A09A60[i], 9);
                        }
                    }
                }
            }
            break;
        default:
            break;
    }
    Matrix_MultVec3f(&this->unkABEC, &this->unkABD4);
    Matrix_MultVec3f(&this->unkABF8, &this->unkABE0);
    if (this->unkABD2 != 0) {
        ShrinkWindow_Letterbox_SetSizeTarget(0x1B);
        Play_SetCameraAtEye(play, this->unkABD2, &this->unkABE0, &this->unkABD4);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F64F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F65F4.s")

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F7400.s")
void func_809F7400(Boss07 *this, PlayState *play, s16 arg2) {
    this->actionFunc = func_809F748C;
    Animation_MorphToLoop(&this->skelAnime, &D_0603CBD0, -10.0f);
    if (arg2 != 0) {
        this->unk150[0] = arg2;
    } else {
        this->unk150[0] = (s16) Rand_ZeroFloat(30.0f);
    }
    this->actor.flags |= 1;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F748C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F7688.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F76D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F77A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F783C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F7968.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F7AB4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F7BC4.s")

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F7D2C.s")
void func_809F7D2C(Boss07* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    this->actionFunc = func_809F805C;
    this->unk150[1] = 0;
    if (player->stateFlags3 & 0x100) {
        this->unk14E = 4;
    } else {
        if (this->actor.xzDistToPlayer <= 300.0f) {
            if (this->actor.xzDistToPlayer <= 200.0f) {
                this->unk14E = 7;
            } else {
                this->unk14E = 4;
            }
        } else {
            this->unk14E = (u32) Rand_ZeroFloat(6.99f);
            if (((s8) this->actor.colChkInfo.health >= 0x1C) && ((this->unk14E == 1) || (this->unk14E == 2))) {
                this->unk14E = 0;
            }
        }
    }
    switch (this->unk14E) {
        case 0:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_06033F80, -5.0f);
            this->unk1D4 = Animation_GetLastFrame(&D_06033F80);
            break;
        case 1:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_06034E64, -5.0f);
            this->unk1D4 = Animation_GetLastFrame(&D_06034E64);
            break;
        case 2:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_060358C4, -5.0f);
            this->unk1D4 = Animation_GetLastFrame(&D_060358C4);
            break;
        case 3:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_06036A7C, -5.0f);
            this->unk1D4 = Animation_GetLastFrame(&D_06036A7C);
            break;
        case 4:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_0603C4E0, -5.0f);
            this->unk1D4 = Animation_GetLastFrame(&D_0603C4E0);
            func_809F4D10(&this->unk164, 650.0f);
            this->unk170 = 0.0f;
            break;
        case 5:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_06037ADC, -5.0f);
            this->unk1D4 = Animation_GetLastFrame(&D_06037ADC);
            break;
        case 6:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_0603918C, -5.0f);
            this->unk1D4 = Animation_GetLastFrame(&D_0603918C);
            break;
        case 7:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_06026204, -5.0f);
            this->unk1D4 = Animation_GetLastFrame(&D_06026204);
            break;
    }
    this->unk14C = 0;
}

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F805C.s")
void func_809F805C(Boss07 *this, PlayState *play) {
    SkelAnime_Update(&this->skelAnime);
    func_809F4CBC(this, 2.0f);
    this->unk794 = 0.79999995f;
    this->unkFA0 = 0.79999995f;
    this->unk790 = -5.0f;
    this->unkF9C = -5.0f;
    this->unk79C = 0.0f;
    this->unkFA8 = 0.0f;
    this->unk798 = 1.0f;
    this->unkFA4 = 1.0f;
    if (this->unk14C >= 0x15) {
        this->unk174 = 1;
    }
    switch (this->unk14E) {
        case 0:
            if (this->unk14C == (s16) (KREG(92) + 1)) {
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            if ((this->unk14C >= 0xF) && (this->unk14C < 0x12)) {
                this->unk79C = 500.0f;
            }
            if (this->unk14C == 9) {
                this->pad14F = 0xB;
            }
            if (this->unk14C == 1) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_HOP_OLD);
            }
            if (this->unk14C == 0xA) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_WIND_OLD);
            }
            break;
        case 1:
            if (this->unk14C == (s16) (KREG(91) + 3)) {
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_THROW_OLD);
            }
            if ((this->unk14C >= 8) && (this->unk14C < 0x38)) {
                this->unk79C = 300.0f;
                this->unkFA8 = 300.0f;
                if (!((this->unk14C + 2) & 3) && (Rand_ZeroOne() < 0.5f)) {
                    play_sound(NA_SE_EN_LAST3_ROD_FLOOR_OLD);
                }
                if (!(this->unk14C & 3)) {
                    Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_WIND_OLD);
                }
                Math_ApproachS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 0xA, 0x1000);
            }
            break;
        case 2:
            if (this->unk14C == (s16) (KREG(84) + 5)) {
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            if ((this->unk14C >= 0x20) && (this->unk14C < 0x27)) {
                this->unk79C = 300.0f;
                this->unkFA8 = 300.0f;
            }
            if (this->unk14C == 0x1C) {
                this->pad14F = 0xB;
            }
            if (this->unk14C == 0xA) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_HOP_OLD);
            }
            if (this->unk14C == 0x20) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_WIND_OLD);
            }
            break;
        case 3:
            if (this->unk14C == (s16) (KREG(84) + 5)) {
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            if ((this->unk14C >= 0x1F) && (this->unk14C < 0x24)) {
                this->unk79C = 1200.0f;
            }
            if (this->unk14C == 0x17) {
                this->pad14F = 0xB;
            }
            Math_ApproachF(&this->unk184, -0.1f, 0.5f, 0.1f);
            Math_ApproachF(&this->unk188, 0.3f, 0.5f, 0.1f);
            if (this->unk14C == 5) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_HOP_OLD);
            }
            if (this->unk14C == 0x1E) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_WIND_OLD);
            }
            break;
        case 4:
            if ((this->unk14C >= 0x11) && (this->unk14C < 0x29)) {
                this->unk79C = 200.0f;
                this->unkFA8 = 200.0f;
                if (!(this->unk14C & 7)) {
                    Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_KOMA_OLD);
                }
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_DANCE_OLD - SFX_FLAG);
                Math_ApproachF(&this->actor.world.pos.x, this->unk164.x, 0.1f, this->unk170);
                Math_ApproachF(&this->actor.world.pos.z, this->unk164.z, 0.1f, this->unk170);
                Math_ApproachF(&this->unk170, 20.0f, 1.0f, 4.0f);
                Math_ApproachS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 5, 0x2000);
                this->unk174 = 0;
            }
            break;
        case 7:
            this->unk174 = 0;
            if (this->unk14C == 3) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_VOICE_KICK_OLD);
            }
            break;
        case 5:
            this->unkFA0 = 0.7f;
            this->unk794 = 0.7f;
            this->unk790 = -15.0f;
            this->unkF9C = -15.0f;
            Math_ApproachS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 0xA, 0x1000);
            this->unk174 = 1;
            break;
        case 6:
            if (this->unk14C == (s16) (KREG(85) + 5)) {
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            if ((this->unk14C >= 0xE) && (this->unk14C < 0x13)) {
                this->unk79C = 150.0f;
            }
            if ((this->unk14C >= 0x17) && (this->unk14C < 0x1D)) {
                this->unkFA8 = 200.0f;
            }
            if ((this->unk14C >= 0x2B) && (this->unk14C < 0x31)) {
                this->unk79C = 200.0f;
            }
            Math_ApproachS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 0xA, 0x1000);
            if (this->unk14C == 0x14) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_HOP_OLD);
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            if (this->unk14C == 5) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_HOP2_OLD);
            }
            if (this->unk14C == 0x29) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_WIND_OLD);
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            break;
    }
    if ((Animation_OnFrame(&this->skelAnime, this->unk1D4) != 0) || (this->unk150[1] == 1)) {
        func_809F7400(this, play, 0);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F8658.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F86B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F87C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F8908.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F8AB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F8B1C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F8D04.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F8DEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F8E68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F8EC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F91D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F9280.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F93DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F94AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F99C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F9CEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F9E94.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/Boss07_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FAA44.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FB114.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FB504.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FB55C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FB728.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FB7D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FBB9C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FBF94.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/Boss07_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FC4C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FC8B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FC960.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FCBC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FCC70.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FCCCC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FD5F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FD710.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FD818.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FD89C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FD984.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FDAB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FDB2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FDBA0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FDEDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FDF54.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FE068.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FE0E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FE2D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FE348.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FE4B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FE524.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FE6B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FE734.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FEE70.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FF0E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FF12C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FF5CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FF678.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FF6B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FF810.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FF900.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FFA04.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FFA80.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FFE64.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809FFEAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A0021C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A00274.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A00484.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A00554.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A006D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A006F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A00720.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A016E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A01750.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A025AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A0264C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A02B30.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A02C54.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A03238.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A036C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A03868.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A03F18.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A03F5C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A0434C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A045A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A04768.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A04878.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A04890.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A04DE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A04E5C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A055E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A05608.s")

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A05694.s")
void func_80A05694(Boss07* this, PlayState* play) {
    u32 i;

    this->unk14C++;
    for(i = 0; i < ARRAY_COUNT(this->unk150); i++) {
        if(this->unk150[i] != 0) {
            this->unk150[i]--;
        }
    }
    if (this->unk18D6 != 0) {
        this->unk18D6--;
    }
    if (this->unk15C != 0) {
        this->unk15C--;
    }
    if (this->unk15E != 0) {
        this->unk15E--;
    }
    this->actionFunc(this, play);
    this->actor.focus.pos = this->actor.world.pos;
    this->actor.world.pos.x += this->unk18CC;
    this->actor.world.pos.z += this->unk18D0;
    Math_ApproachZeroF(&this->unk18CC, 1.0f, 1.0f);
    Math_ApproachZeroF(&this->unk18D0, 1.0f, 1.0f);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A057A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A05AF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A05B50.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A05C88.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A05DDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A06500.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A06990.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A06C64.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A06E24.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A06F48.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A07604.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A07638.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A07740.s")
