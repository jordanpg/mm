#ifndef Z_BOSS_07_H
#define Z_BOSS_07_H

#include "global.h"

struct Boss07;

typedef void (*Boss07ActionFunc)(struct Boss07*, PlayState*);

typedef struct {
    /* 0x00 */ s8 unk_00;
    /* 0x02 */ UNK_TYPE1 unk_01[0x46];
} MajoraEffect; // size = 0x48

#define MAJORA_EFFECT_COUNT 50

typedef struct Boss07 {
    /* 0x0000 */ Actor actor;
    /* 0x0144 */ Boss07ActionFunc actionFunc;
    /* 0x0148 */ char pad148[2];
    /* 0x014A */ s8 unk14A;
    /* 0x014B */ char pad14B[1];
    /* 0x014C */ s16 unk14C;
    /* 0x014E */ u8 unk14E;
    /* 0x014F */ s8 pad14F;
    /* 0x0150 */ s16 unk150[3];
    /* 0x0156 */ char pad156[6];
    /* 0x015C */ s16 unk15C;
    /* 0x015E */ s16 unk15E;
    /* 0x0160 */ char pad160[4];                    /* maybe part of unk15E[3]? */
    /* 0x0164 */ Vec3f unk164;
    /* 0x0170 */ f32 unk170;
    /* 0x0174 */ s8 unk174;
    /* 0x0175 */ char pad175[0xF];                  /* maybe part of unk174[0x10]? */
    /* 0x0184 */ f32 unk184;
    /* 0x0188 */ f32 unk188;
    /* 0x018C */ char pad18C[4];
    /* 0x0190 */ SkelAnime skelAnime;
    /* 0x01D4 */ f32 unk1D4;
    /* 0x01D8 */ char pad1D8[4];
    /* 0x01DC */ Vec3s jointTable[0x1C];
    /* 0x0284 */ Vec3s morphTable[0x1C];
    /* 0x032C */ char pad32C[0xBC];                 /* maybe part of morphTable[2]? */
    /* 0x03E8 */ ColliderJntSph unk3E8;
    /* 0x0408 */ ColliderJntSphElement unk408;
    /* 0x0448 */ char pad448[0x280];                /* maybe part of unk408[0xB]? */
    /* 0x06C8 */ ColliderJntSph unk6C8;
    /* 0x06E8 */ ColliderJntSphElement unk6E8;
    /* 0x0728 */ ColliderCylinder unk728;
    /* 0x0774 */ u8 unk774;
    /* 0x0775 */ char pad775[7];                    /* maybe part of unk774[8]? */
    /* 0x077C */ f32 unk77C;
    /* 0x0780 */ char pad780[0x10];                 /* maybe part of unk77C[5]? */
    /* 0x0790 */ f32 unk790;
    /* 0x0794 */ f32 unk794;
    /* 0x0798 */ f32 unk798;
    /* 0x079C */ f32 unk79C;
    /* 0x07A0 */ char pad7A0[0x7FC];                /* maybe part of unk79C[0x200]? */
    /* 0x0F9C */ f32 unkF9C;
    /* 0x0FA0 */ f32 unkFA0;
    /* 0x0FA4 */ f32 unkFA4;
    /* 0x0FA8 */ f32 unkFA8;
    /* 0x0FAC */ char padFAC[0x80C];                /* maybe part of unkFA8[0x204]? */
    /* 0x17B8 */ f32 unk17B8;
    /* 0x17BC */ f32 unk17BC;
    /* 0x17C0 */ f32 unk17C0;
    /* 0x17C4 */ f32 unk17C4;
    /* 0x17C8 */ char pad17C8[0x10];                /* maybe part of unk17C4[5]? */
    /* 0x17D8 */ s16 unk17D8;
    /* 0x17DA */ s16 unk17DA;
    /* 0x17DC */ s16 unk17DC;
    /* 0x17DE */ char pad17DE[2];
    /* 0x17E0 */ f32 unk17E0;
    /* 0x17E4 */ f32 unk17E4;
    /* 0x17E8 */ f32 unk17E8;
    /* 0x17EC */ char pad17EC[4];
    /* 0x17F0 */ f32 unk17F0;
    /* 0x17F4 */ f32 unk17F4;
    /* 0x17F8 */ char pad17F8[0x10];                /* maybe part of unk17F4[5]? */
    /* 0x1808 */ u8 unk1808;
    /* 0x1809 */ char pad1809[3];                   /* maybe part of unk1808[4]? */
    /* 0x180C */ f32 unk180C;
    /* 0x1810 */ f32 unk1810;
    /* 0x1814 */ f32 unk1814;
    /* 0x1818 */ f32 unk1818;
    /* 0x181C */ s16 unk181C;
    /* 0x181E */ char pad181E[2];
    /* 0x1820 */ ColliderCylinder unk1820;
    /* 0x186C */ char pad186C[0x1C];
    /* 0x1888 */ s8 unk1888;
    /* 0x1889 */ char pad1889[3];                   /* maybe part of unk1888[4]? */
    /* 0x188C */ f32 unk188C;                       /* inferred */
    /* 0x1890 */ char pad1890[0x38];                /* maybe part of unk188C[0xF]? */
    /* 0x18C8 */ s16 unk18C8;                       /* inferred */
    /* 0x18CA */ char pad18CA[2];
    /* 0x18CC */ f32 unk18CC;
    /* 0x18D0 */ f32 unk18D0;
    /* 0x18D4 */ char pad18D4[2];
    /* 0x18D6 */ s16 unk18D6;
    /* 0x18D8 */ char pad18D8[4];                   /* maybe part of unk18D6[3]? */
    /* 0x18DC */ s32 unk18DC;
    /* 0x18E0 */ char pad18E0[0x10];                /* maybe part of unk18DC[5]? */
    /* 0x18F0 */ ColliderQuad unk18F0;
    /* 0x1970 */ ColliderQuad unk1970;
    /* 0x19F0 */ char pad19F0[0x91D8];              /* maybe part of unk1970[0x124]? */
    /* 0xABC8 */ u32 unkABC8;
    /* 0xABCC */ char padABCC[4];
    /* 0xABD0 */ s16 unkABD0;
    /* 0xABD2 */ s16 unkABD2;
    /* 0xABD4 */ Vec3f unkABD4;
    /* 0xABE0 */ Vec3f unkABE0;
    /* 0xABEC */ Vec3f unkABEC;
    /* 0xABF8 */ Vec3f unkABF8;
    /* 0xAC04 */ char padAC04[8];
    /* 0xAC0C */ f32 unkAC0C;
    /* 0xAC10 */ char padAC10[0x10];                /* maybe part of unkAC0C[5]? */
} Boss07;                                           /* size = 0xAC20 */

#endif // Z_BOSS_07_H
