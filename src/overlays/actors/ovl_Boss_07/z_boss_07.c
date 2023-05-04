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
void func_809FAA44(Boss07* this, PlayState* play, Vec3f* arg2, Vec3f* arg3, Vec3f* arg4, Vec3f* arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, Vec3s* argA, s32 argB, f32 argC, s32 argD);
void func_809FB114(Boss07* this, PlayState* play, Vec3f* arg2, Vec3f* arg3, f32 arg4, s32 arg5);
s32 func_809FB504(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx);
void func_809FB55C(PlayState* play, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx);
void func_809FB728(PlayState* play, s32 limbIndex, Actor* thisx);
void func_809FB7D4(Boss07*, PlayState*);
void func_809FBB9C(Boss07*, PlayState*, Vec3f*);
void func_809FC8B0(void*, Boss07*, PlayState*);
void func_809FC960(void*, Boss07*, PlayState*);
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
void func_80A057A0(Actor* thisx, PlayState *play);
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

static Vec3f D_80A07FE0 = { 0.0f, 0.0f, 0.0f };

static Vec3f D_80A084D8 = { 3.1415927f, 0.2f, 0.2f };
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
extern Vec3f D_80A07FE0;
extern Vec3f D_80A084D8;
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

extern void* D_04023348;
extern void* D_04023428;
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
extern void* D_060149A0;
extern void* D_06016090;
extern void* D_06017DE0;
extern void* D_06019328;
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
            Collider_DestroyQuad(play, &this->maskSwrdInfo);
            Collider_DestroyQuad(play, &this->maskSwrdInfo2);
        case 0xB4:
            Effect_Destroy(play, this->blureEffectIndex);
            return;
    }
}

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F5E14.s")
void func_809F5E14(Boss07 *this, PlayState *play) {
    this->actionFunc = func_809F5E88;
    Animation_MorphToLoop(&this->skelAnime, &D_06023DAC, 0.0f);
    this->actor.flags &= ~1;
    this->headAngle.x = 0x7F00;
    this->damage = 0x14;
    this->hensinScaleS1 = 5120.0f;
}

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F5E88.s")
void func_809F5E88(Boss07 *this, PlayState *play) {
    Player* player;
    u32 i;
    u32 index;
    Camera *camera;

    this->damage = 0x14;
    SkelAnime_Update(&this->skelAnime);
    this->demoTime++;
    Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, MTXMODE_NEW);
    Matrix_RotateYS(this->actor.shape.rot.y, MTXMODE_APPLY);

    switch(this->demoMode) {
        case 0:
            this->demoTime = 0;
            this->demoMode = 1;
            this->wayTarget.z = 0.0f;
            this->eyeTarget.x = 0.0f;
            this->eyeTarget.y = (((f32) KREG(17) + 100.0f) - 30.0f) + 80.0f;
            this->eyeTarget.z = ((((f32) KREG(18) + 270.0f) - 150.0f) + 30.0f) - 50.0f;
            this->wayTarget.x = 0.0f;
            this->wayTarget.y = 180.0f;
        case 1:
            if (this->demoTime < 0x28U) {
                D_80A09A4C = 3;
            }
            if (this->demoTime >= 0x15U) {
                if (this->demoTime == 0x15) {
                    Actor_PlaySfx(&this->actor, NA_SE_EN_LAST2_GROW_HEAD_OLD);
                }
                Math_ApproachS(&this->headAngle.x, 0, 5, 0x1000);
                this->headAngle.y = (s16) (Math_SinS((this->demoTime << 0xC)) * this->hensinScaleS1);
                this->headAngle.z = (s16) (Math_SinS((this->demoTime * 0xB00)) * this->hensinScaleS1 * 0.5f);
                if (this->demoTime >= 0x29U) {
                    Math_ApproachZeroF(&this->hensinScaleS1, 1.0f, 200.0f);
                }
            }
            if (this->demoTime >= 0x3DU) {
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
                Math_ApproachF(&this->eyeTarget.y, D_80A07F6C[index].x, 0.075f, this->cameraMorf * 7.0f);
                Math_ApproachF(&this->eyeTarget.z, D_80A07F6C[index].y, 0.075f, this->cameraMorf * 17.0f);
                Math_ApproachF(&this->wayTarget.y, D_80A07F6C[index].z, 0.075f, this->cameraMorf * 7.0f);
                Math_ApproachF(&this->cameraMorf, 1.0f, 1.0f, 0.01f);
                if (this->demoTime == 0x46) {
                    Animation_MorphToPlayOnce(&this->skelAnime, (AnimationHeader *) &D_06025018, -15.0f);
                    this->endFrame = (f32) Animation_GetLastFrame(&D_06025018);
                    func_8019FE1C(&this->actor.projectedPos, 0x290D, 0x3F800000);
                    Actor_PlaySfx(&this->actor, NA_SE_EN_LAST2_SHOUT);
                }
                if (this->demoTime >= 0x6EU) {
                    Math_ApproachF(&this->mutiBaseScale, 1.0f, 1.0f, 0.05f);
                    this->kanseiPower = 0.79999995f;
                    this->kanseiPower2 = 0.79999995f;
                    this->kanseiBrake = 1.0f;
                    this->kanseiBrake2 = 1.0f;
                }
                if (this->demoTime == 0x7F) {
                    this->mutiBaseScale = 1.0f;
                }
                if (this->demoTime == 0x78) {
                    Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_HOP2_OLD);
                    Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_KICK_OLD);
                    func_8019FE74(&gSfxVolume, 0.0f, 0x3C);
                }
                if (this->demoTime == 0x70) {
                    AudioSeq_QueueSeqCmd(0x8069U);
                }
                if (this->demoTime == 0x89) {
                    TitleCard_InitBossName(&play->state, &play->actorCtx.titleCtxt, Lib_SegmentedToVirtual(&D_06032040), 0xA0, 0xB4, 0x80, 0x28);
                }
                if (Animation_OnFrame(&this->skelAnime, this->endFrame) != 0) {
                    camera = Play_GetCamera(play, 0);
                    this->demoMode = 0;
                    func_809F7400(this, play, 0x32);
                    camera->eye = this->eye;
                    camera->eyeNext = this->eye;
                    camera->at = this->way;
                    func_80169AFC(play, this->cameraNo, 0);
                    this->cameraNo = 0;
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
    Matrix_MultVec3f(&this->eyeTarget, &this->eye);
    Matrix_MultVec3f(&this->wayTarget, &this->way);
    if (this->cameraNo != 0) {
        ShrinkWindow_Letterbox_SetSizeTarget(0x1B);
        Play_SetCameraAtEye(play, this->cameraNo, &this->way, &this->eye);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F64F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F65F4.s")

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F7400.s")
void func_809F7400(Boss07 *this, PlayState *play, s16 arg2) {
    this->actionFunc = func_809F748C;
    Animation_MorphToLoop(&this->skelAnime, &D_0603CBD0, -10.0f);
    if (arg2 != 0) {
        this->timer[0] = arg2;
    } else {
        this->timer[0] = (s16) Rand_ZeroFloat(30.0f);
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
    this->timer[1] = 0;
    if (player->stateFlags3 & 0x100) {
        this->moveMode = 4;
    } else {
        if (this->actor.xzDistToPlayer <= 300.0f) {
            if (this->actor.xzDistToPlayer <= 200.0f) {
                this->moveMode = 7;
            } else {
                this->moveMode = 4;
            }
        } else {
            this->moveMode = (u32) Rand_ZeroFloat(6.99f);
            if (((s8) this->actor.colChkInfo.health >= 0x1C) && ((this->moveMode == 1) || (this->moveMode == 2))) {
                this->moveMode = 0;
            }
        }
    }
    switch (this->moveMode) {
        case 0:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_06033F80, -5.0f);
            this->endFrame = Animation_GetLastFrame(&D_06033F80);
            break;
        case 1:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_06034E64, -5.0f);
            this->endFrame = Animation_GetLastFrame(&D_06034E64);
            break;
        case 2:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_060358C4, -5.0f);
            this->endFrame = Animation_GetLastFrame(&D_060358C4);
            break;
        case 3:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_06036A7C, -5.0f);
            this->endFrame = Animation_GetLastFrame(&D_06036A7C);
            break;
        case 4:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_0603C4E0, -5.0f);
            this->endFrame = Animation_GetLastFrame(&D_0603C4E0);
            func_809F4D10(&this->target, 650.0f);
            this->targetSp = 0.0f;
            break;
        case 5:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_06037ADC, -5.0f);
            this->endFrame = Animation_GetLastFrame(&D_06037ADC);
            break;
        case 6:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_0603918C, -5.0f);
            this->endFrame = Animation_GetLastFrame(&D_0603918C);
            break;
        case 7:
            Animation_MorphToPlayOnce(&this->skelAnime, &D_06026204, -5.0f);
            this->endFrame = Animation_GetLastFrame(&D_06026204);
            break;
    }
    this->count = 0;
}

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F805C.s")
void func_809F805C(Boss07 *this, PlayState *play) {
    SkelAnime_Update(&this->skelAnime);
    func_809F4CBC(this, 2.0f);
    this->kanseiPower = 0.79999995f;
    this->kanseiPower2 = 0.79999995f;
    this->mutiG = -5.0f;
    this->mutiG2 = -5.0f;
    this->hari = 0.0f;
    this->hari2 = 0.0f;
    this->kanseiBrake = 1.0f;
    this->kanseiBrake2 = 1.0f;
    if (this->count >= 0x15) {
        this->defenseOk = 1;
    }
    switch (this->moveMode) {
        case 0:
            if (this->count == (s16) (KREG(92) + 1)) {
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            if ((this->count >= 0xF) && (this->count < 0x12)) {
                this->hari = 500.0f;
            }
            if (this->count == 9) {
                this->swingSe = 0xB;
            }
            if (this->count == 1) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_HOP_OLD);
            }
            if (this->count == 0xA) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_WIND_OLD);
            }
            break;
        case 1:
            if (this->count == (s16) (KREG(91) + 3)) {
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_THROW_OLD);
            }
            if ((this->count >= 8) && (this->count < 0x38)) {
                this->hari = 300.0f;
                this->hari2 = 300.0f;
                if (!((this->count + 2) & 3) && (Rand_ZeroOne() < 0.5f)) {
                    play_sound(NA_SE_EN_LAST3_ROD_FLOOR_OLD);
                }
                if (!(this->count & 3)) {
                    Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_WIND_OLD);
                }
                Math_ApproachS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 0xA, 0x1000);
            }
            break;
        case 2:
            if (this->count == (s16) (KREG(84) + 5)) {
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            if ((this->count >= 0x20) && (this->count < 0x27)) {
                this->hari = 300.0f;
                this->hari2 = 300.0f;
            }
            if (this->count == 0x1C) {
                this->swingSe = 0xB;
            }
            if (this->count == 0xA) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_HOP_OLD);
            }
            if (this->count == 0x20) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_WIND_OLD);
            }
            break;
        case 3:
            if (this->count == (s16) (KREG(84) + 5)) {
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            if ((this->count >= 0x1F) && (this->count < 0x24)) {
                this->hari = 1200.0f;
            }
            if (this->count == 0x17) {
                this->swingSe = 0xB;
            }
            Math_ApproachF(&this->hoseiYa, -0.1f, 0.5f, 0.1f);
            Math_ApproachF(&this->hoseiXa, 0.3f, 0.5f, 0.1f);
            if (this->count == 5) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_HOP_OLD);
            }
            if (this->count == 0x1E) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_WIND_OLD);
            }
            break;
        case 4:
            if ((this->count >= 0x11) && (this->count < 0x29)) {
                this->hari = 200.0f;
                this->hari2 = 200.0f;
                if (!(this->count & 7)) {
                    Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_KOMA_OLD);
                }
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_DANCE_OLD - SFX_FLAG);
                Math_ApproachF(&this->actor.world.pos.x, this->target.x, 0.1f, this->targetSp);
                Math_ApproachF(&this->actor.world.pos.z, this->target.z, 0.1f, this->targetSp);
                Math_ApproachF(&this->targetSp, 20.0f, 1.0f, 4.0f);
                Math_ApproachS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 5, 0x2000);
                this->defenseOk = 0;
            }
            break;
        case 7:
            this->defenseOk = 0;
            if (this->count == 3) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_VOICE_KICK_OLD);
            }
            break;
        case 5:
            this->kanseiPower2 = 0.7f;
            this->kanseiPower = 0.7f;
            this->mutiG = -15.0f;
            this->mutiG2 = -15.0f;
            Math_ApproachS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 0xA, 0x1000);
            this->defenseOk = 1;
            break;
        case 6:
            if (this->count == (s16) (KREG(85) + 5)) {
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            if ((this->count >= 0xE) && (this->count < 0x13)) {
                this->hari = 150.0f;
            }
            if ((this->count >= 0x17) && (this->count < 0x1D)) {
                this->hari2 = 200.0f;
            }
            if ((this->count >= 0x2B) && (this->count < 0x31)) {
                this->hari = 200.0f;
            }
            Math_ApproachS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 0xA, 0x1000);
            if (this->count == 0x14) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_HOP_OLD);
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            if (this->count == 5) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_HOP2_OLD);
            }
            if (this->count == 0x29) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_WIND_OLD);
                Audio_PlaySfxAtPos(&D_80A09A40, NA_SE_EN_LAST3_VOICE_ROD_OLD);
            }
            break;
    }
    if ((Animation_OnFrame(&this->skelAnime, this->endFrame) != 0) || (this->timer[1] == 1)) {
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

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_809F8EC8.s")
void func_809F8EC8(Boss07* this, PlayState* play) {
    s16 var_a1;

    this->hitOk = 0x14;
    if (this->count < (s16) (KREG(40) + 0xE)) {
        this->mutiKoma += 6;
        if (this->mutiKoma >= 0x2D) {
            this->mutiKoma = 0x2C;
        }
    }

    if(this->count == 0) {
        // Do nothing...
    }
    
    if (this->count == 8) {
        Actor_Spawn(&play->actorCtx, play, 0x12F, this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, 0xB4);
    }
    if (this->count == 0xA) {
        Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_ROD_WIND_OLD);
    }
    if (this->count == (s16) (KREG(40) + 0x12)) {
        Actor_PlaySfx(&this->actor, NA_SE_EN_LAST3_VOICE_KOMA_OLD);
    }
    var_a1 = (KREG(40) + 0xE);
    if ((this->count < var_a1) || ((s16) (KREG(41) + 0x11) < this->count)) {
        SkelAnime_Update(&this->skelAnime);
        var_a1 = KREG(40) + 0xE;
    }
    if ((this->count >= var_a1) && (((s16) (KREG(41) + 0x11) >= this->count) || (this->count >= (s16) (KREG(42) + 0x15)))) {
        this->mutiKoma -= KREG(39) + 5;
        if (this->mutiKoma < 0) {
            this->mutiKoma = 0;
        }
    }
    Math_ApproachS(&this->actor.shape.rot.y, (s16) ((KREG(8) << 8) + this->actor.yawTowardsPlayer + 0xF00), 3, 0x2000);
    func_809F4CBC(this, 2.0f);
    
    this->kanseiPower = 0.79999995f;
    this->kanseiPower2 = 0.79999995f;
    this->kanseiBrake = 1.0f;
    this->kanseiBrake2 = 1.0f;
    this->mutiG = -5.0f;
    this->hari = 0.0f;
    this->hari2 = 0.0f;
    this->mutiG2 = -15.0f;
    if ((this->count >= (s16) (KREG(43) + 0xC)) && ((s16) (KREG(44) + 0x11) >= this->count)) {
        this->hari = (f32) KREG(6) + 500.0f;
    }
    if (this->count >= (s16) (KREG(45) + 0x24)) {
        func_809F7400(this, play, Rand_ZeroFloat(20.0f) + 20.0f);
    }
}

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

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/Boss07_Draw.s")
void Boss07_Draw(Actor* thisx, PlayState* play) {
    char pad[6];
    void* graph;
    GraphicsContext* __gfxCtx;
    Boss07* this = (Boss07* ) thisx;
    Vec3f newPos;

    graph = GRAPH_ALLOC(play->state.gfxCtx, 0x1000);
    __gfxCtx = play->state.gfxCtx;
    func_8012C28C(play->state.gfxCtx);
    func_8012C2DC(play->state.gfxCtx);
    if (this->damageFlash & 1) {
        __gfxCtx->polyOpa.p = Gfx_SetFog(__gfxCtx->polyOpa.p, 0xFF, 0, 0, 0xFF, 0x384, 0x44B);
    }
    Matrix_RotateYF(this->hoseiYa, MTXMODE_APPLY);
    Matrix_RotateXFApply(this->hoseiXa);
    SkelAnime_DrawTransformFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount, func_809FB504, func_809FB55C, func_809FB728, &this->actor);
    __gfxCtx->polyOpa.p = Play_SetFog(play, __gfxCtx->polyOpa.p);
    if (((KREG(63) == 0) || (KREG(63) == 2)) && (this->moveFlag != 0)) {
        func_809FAA44(this, play, &this->mutiBasePos, this->mutiPos, this->mutiAngle, this->mutiSpd, this->mutiG, this->kanseiPower, this->kanseiBrake, this->hari, &this->handA, this->maki, this->mutiBaseScale, 0);
        func_809FAA44(this, play, &this->mutiBasePos2, this->mutiPos2, this->mutiAngle2, this->mutiSpd2, this->mutiG2, this->kanseiPower2, this->kanseiBrake2, this->hari2, &this->handA2, 0, this->mutiBaseScale, 1);
    }

    func_809FB114(this, play, this->mutiPos, this->mutiAngle, this->mutiBaseScale, 0);
    func_809FB114(this, play, this->mutiPos2, this->mutiAngle2, this->mutiBaseScale, 1);
    if (this->shadowOff == 0) {
        func_809FC8B0(graph, this, play);
        func_809FC960(graph, this, play);
    }
    func_809FB7D4(this, play);
    newPos.x = this->shapePos[2].x;
    newPos.y = (this->shapePos[2].y - 30.0f) + 50.0f;
    newPos.z = this->shapePos[2].z;
    func_809FBB9C(this, play, &newPos);
    Actor_DrawDamageEffects(play, &this->actor, this->shapePos, 0xF, this->effScale1, this->effScale2, this->effAlpha, this->effNo);
    this->moveFlag = 0;
}

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
/** Update function when params >= 0xC8 (remains?); handles damage knockback & related timers */
void func_80A05694(Boss07* this, PlayState* play) {
    u32 i;

    this->count++;
    for(i = 0; i < ARRAY_COUNT(this->timer); i++) {
        if(this->timer[i] != 0) {
            this->timer[i]--;
        }
    }
    if (this->fireTime != 0) {
        this->fireTime--;
    }
    if (this->damage != 0) {
        this->damage--;
    }
    if (this->damageFlash != 0) {
        this->damageFlash--;
    }
    this->actionFunc(this, play);
    this->actor.focus.pos = this->actor.world.pos;
    this->actor.world.pos.x += this->damageSpeedX;
    this->actor.world.pos.z += this->damageSpeedZ;
    Math_ApproachZeroF(&this->damageSpeedX, 1.0f, 1.0f);
    Math_ApproachZeroF(&this->damageSpeedZ, 1.0f, 1.0f);
}

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_07/func_80A057A0.s")
/** Remains draw function? */
void func_80A057A0(Actor* thisx, PlayState* play) {
    char pad[8];
    f32 sp64;
    f32 sp60;
    Boss07* this = (Boss07*)thisx;
    char pad2[2];
    GraphicsContext* __gfxCtx;

    __gfxCtx = play->state.gfxCtx;
    func_8012C28C(play->state.gfxCtx);
    if (this->damageFlash & 1) {
        __gfxCtx->polyOpa.p = Gfx_SetFog(__gfxCtx->polyOpa.p, 0xFF, 0, 0, 0xFF, 0x384, 0x44B);
    }
    sp64 = this->damage * DEG_TO_RAD(45) * 0.06666667f;
    sp60 = Math_SinS(this->damage * 0x3500) * sp64 * 0.5f;
    Matrix_RotateYF(Math_SinS(this->damage * 0x4500) * sp64, MTXMODE_APPLY);
    Matrix_RotateXFApply(sp60);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(play->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    switch (this->actor.params) {
        case 0xC8:
            gSPDisplayList(POLY_OPA_DISP++, &D_060149A0);
            break;
        case 0xC9:
            gSPDisplayList(POLY_OPA_DISP++, &D_06016090);
            break;
        case 0xCA:
            gSPDisplayList(POLY_OPA_DISP++, &D_06017DE0);
            break;
        case 0xCB:
            gSPDisplayList(POLY_OPA_DISP++, &D_06019328);
            break;
    }
    __gfxCtx->polyOpa.p = Play_SetFog(play, __gfxCtx->polyOpa.p);
    if (this->actionFunc == func_80A04890) {
        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0xFF, 0xFF, 0xC8, 0xC8);
        gDPSetEnvColor(POLY_XLU_DISP++, 0xFF, 0xFF, 0x64, 0x80);
        Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, MTXMODE_NEW);
        Matrix_Scale(this->beamScale1, this->beamScale1, 0.0f, MTXMODE_APPLY);
        Matrix_ReplaceRotation(&play->billboardMtxF);
        Matrix_RotateZS(this->beamSang.z, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(play->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, &D_04023348);
        gSPDisplayList(POLY_XLU_DISP++, &D_04023428);
    }
}

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
