#ifndef Z_BOSS_07_H
#define Z_BOSS_07_H

#include "global.h"

struct Boss07;

typedef void (*Boss07ActionFunc)(struct Boss07*, PlayState*);

typedef struct {
    /* 0x00 */ s8 unk_00;
    /* 0x02 */ UNK_TYPE1 unk_01[0x46];
} MajoraEffect; // size = 0x48

typedef struct {
    /* 0x00 */ char pad00[0x174];
} MajoraHair;

#define MAJORA_EFFECT_COUNT 50

typedef struct Boss07 {
    /* 0x0000 */ Actor actor;
    /* 0x0144 */ Boss07ActionFunc actionFunc;
    /* 0x0148 */ u8 changeFlag;
    /* 0x0149 */ u8 moveFlag;
    /* 0x014A */ u8 kankyoSw;
    /* 0x014B */ u8 kankyoCount;
    /* 0x014C */ s16 count;
    /* 0x014E */ u8 moveMode;
    /* 0x014F */ s8 swingSe;
    /* 0x0150 */ s16 timer[3];
    /* 0x0156 */ s16 landSeTime;
    /* 0x0158 */ s16 noHit;
    /* 0x015A */ s16 hitOk;
    /* 0x015C */ s16 damage;
    /* 0x015E */ s16 damageFlash;
    /* 0x0160 */ s16 ILL_A;
    /* 0x0164 */ Vec3f target;
    /* 0x0170 */ f32 targetSp;
    /* 0x0174 */ s8 defenseOk;
    /* 0x0178 */ f32 spinAngle;
    /* 0x017C */ f32 spinAngleSpd;
    /* 0x0180 */ f32 spinAngleSSpd;
    /* 0x0184 */ f32 hoseiYa;
    /* 0x0188 */ f32 hoseiXa;
    /* 0x018C */ f32 baseSpeed;
    /* 0x0190 */ SkelAnime skelAnime;
    /* 0x01D4 */ f32 endFrame;
    /* 0x01D8 */ s32 meshSpeed;
    /* 0x01DC */ Vec3s jointTable[28];
    /* 0x0284 */ Vec3s morphTable[28];
    /* 0x032C */ f32 shapeFlashSize;
    /* 0x0330 */ f32 shapeDecalSize;
    /* 0x0334 */ Vec3f shapePos[15];
    /* 0x03E8 */ ColliderJntSph bodyJntSphInfo;
    /* 0x0408 */ ColliderJntSphElement bodyJntSphElem[11];
    /* 0x06C8 */ ColliderJntSph sudeJntSphInfo;
    /* 0x06E8 */ ColliderJntSphElement sudeJntSphElem[1];
    /* 0x0728 */ ColliderCylinder defCylInfo;
    /* 0x0774 */ u8 faceDemoStart;
    /* 0x0778 */ s32 mutiKoma;
    /* 0x077C */ f32 mutiBaseScale;
    /* 0x0780 */ f32 mutiFlashCt1;
    /* 0x0784 */ f32 mutiFlashCt2;
    /* 0x0788 */ Vec3s handA;
    /* 0x0790 */ f32 mutiG;
    /* 0x0794 */ f32 kanseiPower;
    /* 0x0798 */ f32 kanseiBrake;
    /* 0x079C */ f32 hari;
    /* 0x07A0 */ Vec3f mutiBasePos;
    /* 0x07AC */ Vec3f mutiPos[50];
    /* 0x0A04 */ Vec3f mutiAngle[50];
    /* 0x0C5C */ Vec3f mutiSpd[50];
    /* 0x0EB4 */ float mutiGroundY[50];
    /* 0x0F7C */ s16 makiCount;
    /* 0x0F7E */ s16 maki;
    /* 0x0F80 */ Vec3f makiPos;
    /* 0x0F8C */ f32 makiYa;
    /* 0x0F90 */ f32 makiXa;
    /* 0x0F94 */ Vec3s handA2;
    /* 0x0F9C */ f32 mutiG2;
    /* 0x0FA0 */ f32 kanseiPower2;
    /* 0x0FA4 */ f32 kanseiBrake2;
    /* 0x0FA8 */ f32 hari2;
    /* 0x0FAC */ Vec3f mutiBasePos2;
    /* 0x0FB8 */ Vec3f mutiPos2[50];
    /* 0x1210 */ Vec3f mutiAngle2[50];
    /* 0x1468 */ Vec3f mutiSpd2[50];
    /* 0x16C0 */ float mutiGroundY2[50];
    /* 0x1788 */ Vec3f footPos[2];
    /* 0x17A0 */ Vec3f handPosL;
    /* 0x17AC */ Vec3f handPosR;
    /* 0x17B8 */ f32 partsScale[4];
    /* 0x17C8 */ f32 partsScaleS[4];
    /* 0x17D8 */ Vec3s headAngle;
    /* 0x17E0 */ f32 hensinScale1;
    /* 0x17E4 */ f32 hensinScale2;
    /* 0x17E8 */ f32 hensinScaleS1;
    /* 0x17EC */ f32 hensinScaleS2;
    /* 0x17F0 */ f32 cestScaleX;
    /* 0x17F4 */ f32 cestScaleY;
    /* 0x17F8 */ f32 effScale1;
    /* 0x17FC */ f32 effScale2;
    /* 0x1800 */ f32 effAlpha;
    /* 0x1804 */ u8 effNo;
    /* 0x1805 */ u8 effMode;
    /* 0x1806 */ s16 effTime;
    /* 0x1808 */ u8 feeFlag;
    /* 0x180C */ f32 feeScale;
    /* 0x1810 */ Vec3f feePos;
    /* 0x181C */ s16 colorNo;
    /* 0x1820 */ ColliderCylinder cylInfo;
    /* 0x186C */ s16 shock;
    /* 0x1870 */ f32 hairBaseSize;
    /* 0x1874 */ u8 hairMode;
    /* 0x1878 */ Vec3f maskBasePos;
    /* 0x1884 */ s32 texNo;
    /* 0x1888 */ u8 bgCheckOk;
    /* 0x188C */ f32 beamScale1;
    /* 0x1890 */ f32 beamScale12;
    /* 0x1894 */ f32 beamRange;
    /* 0x1898 */ f32 beamScaleBase;
    /* 0x189C */ Vec3f beamPos;
    /* 0x18A8 */ Vec3f beamPos2;
    /* 0x18B4 */ Vec3f beamPos3;
    /* 0x18C0 */ f32 beamRange2;
    /* 0x18C4 */ Vec3s beamSang;
    /* 0x18CC */ f32 damageSpeedX;
    /* 0x18D0 */ f32 damageSpeedZ;
    /* 0x18D4 */ s16 maskSpinSpd;
    /* 0x18D6 */ s16 fireTime;
    /* 0x18D8 */ s16 beamTime;
    /* 0x18DA */ u8 fireMode;
    /* 0x18DB */ u8 beamOn;
    /* 0x18DC */ s32 blureEffectIndex;
    /* 0x18E0 */ Vec3f beamOldPos;
    /* 0x18EC */ u8 beamKoge;
    /* 0x18ED */ u8 beamKogeOld;
    /* 0x18F0 */ ColliderQuad maskSwrdInfo;
    /* 0x1970 */ ColliderQuad maskSwrdInfo2;
    /* 0x19F0 */ MajoraHair hair[100];
    /* 0xAB40 */ s16 faceCount;
    /* 0xAB44 */ f32 demoPlayerBall;
    /* 0xAB48 */ u8 shadowOff;
    /* 0xAB4C */ f32 demoBeamSize0;
    /* 0xAB50 */ f32 demoBeamSize[30];
    /* 0xABC8 */ u32 demoTime;
    /* 0xABCC */ u32 demoTime2;
    /* 0xABD0 */ s16 demoMode;
    /* 0xABD2 */ s16 cameraNo;
    /* 0xABD4 */ Vec3f eye;
    /* 0xABE0 */ Vec3f way;
    /* 0xABEC */ Vec3f eyeTarget;
    /* 0xABF8 */ Vec3f wayTarget;
    /* 0xAC04 */ f32 eyeAngleY;
    /* 0xAC08 */ f32 eyeAngleYS;
    /* 0xAC0C */ f32 cameraMorf;
    /* 0xAC10 */ f32 cameraMorfSpd;
    /* 0xAC14 */ f32 fwork;
    /* 0xAC18 */ f32 demoJisinY;
    /* 0xAC1C */ f32 demoJisinYA;
} Boss07;                                           /* size = 0xAC20 */

#endif // Z_BOSS_07_H
