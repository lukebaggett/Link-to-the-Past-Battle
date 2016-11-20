/*
 * Exported with nin10kit v1.3
 * Invocation command was nin10kit -force=1 -mode=sprites sprites death0.png death1.png death2.png death3.png linkdeathD.png linkdeathF.png linkdeathU.png linkmoveD0.png linkmoveD1.png linkmoveD2.png linkmoveD3.png linkmoveD4.png linkmoveD5.png linkmoveD6.png linkmoveF0.png linkmoveF1.png linkmoveF2.png linkmoveF3.png linkmoveF4.png linkmoveF5.png linkmoveF6.png linkmoveU0.png linkmoveU1.png linkmoveU2.png linkmoveU3.png linkmoveU4.png linkmoveU5.png linkmoveU6.png linkpose0.png linkstrikeD0.png linkstrikeD1.png linkstrikeD2.png linkstrikeD3.png linkstrikeD4.png linkstrikeD5.png linkstrikeF0.png linkstrikeF1.png linkstrikeF2.png linkstrikeF3.png linkstrikeF4.png linkstrikeF5.png linkstrikeF6.png linkstrikeF7.png linkstrikeF8.png linkstrikeU0.png linkstrikeU1.png linkstrikeU2.png linkstrikeU3.png linkstrikeU4.png linkstrikeU5.png linkstrikeU6.png linkstrikeU7.png linkstrikeU8.png popo0.png popo1.png popo2.png sword.png triforce.png 
 * Time-stamp: Tuesday 11/08/2016, 06:34:16
 * 
 * Image Information
 * -----------------
 * death0.png 32@32
 * death1.png 32@32
 * death2.png 32@32
 * death3.png 32@32
 * linkdeathD.png 32@32
 * linkdeathF.png 32@32
 * linkdeathU.png 32@32
 * linkmoveD0.png 32@32
 * linkmoveD1.png 32@32
 * linkmoveD2.png 32@32
 * linkmoveD3.png 32@32
 * linkmoveD4.png 32@32
 * linkmoveD5.png 32@32
 * linkmoveD6.png 32@32
 * linkmoveF0.png 32@32
 * linkmoveF1.png 32@32
 * linkmoveF2.png 32@32
 * linkmoveF3.png 32@32
 * linkmoveF4.png 32@32
 * linkmoveF5.png 32@32
 * linkmoveF6.png 32@32
 * linkmoveU0.png 32@32
 * linkmoveU1.png 32@32
 * linkmoveU2.png 32@32
 * linkmoveU3.png 32@32
 * linkmoveU4.png 32@32
 * linkmoveU5.png 32@32
 * linkmoveU6.png 32@32
 * linkpose0.png 32@32
 * linkstrikeD0.png 32@32
 * linkstrikeD1.png 32@32
 * linkstrikeD2.png 32@32
 * linkstrikeD3.png 32@32
 * linkstrikeD4.png 32@32
 * linkstrikeD5.png 32@32
 * linkstrikeF0.png 32@32
 * linkstrikeF1.png 32@32
 * linkstrikeF2.png 32@32
 * linkstrikeF3.png 32@32
 * linkstrikeF4.png 32@32
 * linkstrikeF5.png 32@32
 * linkstrikeF6.png 32@32
 * linkstrikeF7.png 32@32
 * linkstrikeF8.png 32@32
 * linkstrikeU0.png 32@32
 * linkstrikeU1.png 32@32
 * linkstrikeU2.png 32@32
 * linkstrikeU3.png 32@32
 * linkstrikeU4.png 32@32
 * linkstrikeU5.png 32@32
 * linkstrikeU6.png 32@32
 * linkstrikeU7.png 32@32
 * linkstrikeU8.png 32@32
 * popo0.png 32@32
 * popo1.png 32@32
 * popo2.png 32@32
 * sword.png 8@16
 * triforce.png 32@64
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * 
 * All bug reports / feature requests are to be sent to Brandon (bwhitehead0308@gmail.com)
 */

#ifndef SPRITES_H
#define SPRITES_H

#define DEATH_FRAMES 4
#define LINKMOVED_FRAMES 7
#define LINKMOVEU_FRAMES 7
#define LINKMOVEF_FRAMES 7
#define LINKSTRIKED_FRAMES 6
#define LINKSTRIKEF_FRAMES 9
#define LINKSTRIKEU_FRAMES 9
#define POPO_FRAMES 3

#define SPRITES_PALETTE_TYPE (1 << 13)
#define SPRITES_DIMENSION_TYPE (1 << 6)

extern const unsigned short sprites_palette[61];
#define SPRITES_PALETTE_SIZE 61

extern const unsigned short sprites_data[29760];
#define SPRITES_SIZE 29760

#define DEATH0_SPRITE_SHAPE (0 << 14)
#define DEATH0_SPRITE_SIZE (2 << 14)
#define DEATH0_ID 0

#define DEATH1_SPRITE_SHAPE (0 << 14)
#define DEATH1_SPRITE_SIZE (2 << 14)
#define DEATH1_ID 32

#define DEATH2_SPRITE_SHAPE (0 << 14)
#define DEATH2_SPRITE_SIZE (2 << 14)
#define DEATH2_ID 64

#define DEATH3_SPRITE_SHAPE (0 << 14)
#define DEATH3_SPRITE_SIZE (2 << 14)
#define DEATH3_ID 96

#define LINKDEATHD_SPRITE_SHAPE (0 << 14)
#define LINKDEATHD_SPRITE_SIZE (2 << 14)
#define LINKDEATHD_ID 128

#define LINKDEATHF_SPRITE_SHAPE (0 << 14)
#define LINKDEATHF_SPRITE_SIZE (2 << 14)
#define LINKDEATHF_ID 160

#define LINKDEATHU_SPRITE_SHAPE (0 << 14)
#define LINKDEATHU_SPRITE_SIZE (2 << 14)
#define LINKDEATHU_ID 192

#define LINKMOVED0_SPRITE_SHAPE (0 << 14)
#define LINKMOVED0_SPRITE_SIZE (2 << 14)
#define LINKMOVED0_ID 224

#define LINKMOVED1_SPRITE_SHAPE (0 << 14)
#define LINKMOVED1_SPRITE_SIZE (2 << 14)
#define LINKMOVED1_ID 256

#define LINKMOVED2_SPRITE_SHAPE (0 << 14)
#define LINKMOVED2_SPRITE_SIZE (2 << 14)
#define LINKMOVED2_ID 288

#define LINKMOVED3_SPRITE_SHAPE (0 << 14)
#define LINKMOVED3_SPRITE_SIZE (2 << 14)
#define LINKMOVED3_ID 320

#define LINKMOVED4_SPRITE_SHAPE (0 << 14)
#define LINKMOVED4_SPRITE_SIZE (2 << 14)
#define LINKMOVED4_ID 352

#define LINKMOVED5_SPRITE_SHAPE (0 << 14)
#define LINKMOVED5_SPRITE_SIZE (2 << 14)
#define LINKMOVED5_ID 384

#define LINKMOVED6_SPRITE_SHAPE (0 << 14)
#define LINKMOVED6_SPRITE_SIZE (2 << 14)
#define LINKMOVED6_ID 416

#define LINKMOVEF0_SPRITE_SHAPE (0 << 14)
#define LINKMOVEF0_SPRITE_SIZE (2 << 14)
#define LINKMOVEF0_ID 448

#define LINKMOVEF1_SPRITE_SHAPE (0 << 14)
#define LINKMOVEF1_SPRITE_SIZE (2 << 14)
#define LINKMOVEF1_ID 480

#define LINKMOVEF2_SPRITE_SHAPE (0 << 14)
#define LINKMOVEF2_SPRITE_SIZE (2 << 14)
#define LINKMOVEF2_ID 512

#define LINKMOVEF3_SPRITE_SHAPE (0 << 14)
#define LINKMOVEF3_SPRITE_SIZE (2 << 14)
#define LINKMOVEF3_ID 544

#define LINKMOVEF4_SPRITE_SHAPE (0 << 14)
#define LINKMOVEF4_SPRITE_SIZE (2 << 14)
#define LINKMOVEF4_ID 576

#define LINKMOVEF5_SPRITE_SHAPE (0 << 14)
#define LINKMOVEF5_SPRITE_SIZE (2 << 14)
#define LINKMOVEF5_ID 608

#define LINKMOVEF6_SPRITE_SHAPE (0 << 14)
#define LINKMOVEF6_SPRITE_SIZE (2 << 14)
#define LINKMOVEF6_ID 640

#define LINKMOVEU0_SPRITE_SHAPE (0 << 14)
#define LINKMOVEU0_SPRITE_SIZE (2 << 14)
#define LINKMOVEU0_ID 672

#define LINKMOVEU1_SPRITE_SHAPE (0 << 14)
#define LINKMOVEU1_SPRITE_SIZE (2 << 14)
#define LINKMOVEU1_ID 704

#define LINKMOVEU2_SPRITE_SHAPE (0 << 14)
#define LINKMOVEU2_SPRITE_SIZE (2 << 14)
#define LINKMOVEU2_ID 736

#define LINKMOVEU3_SPRITE_SHAPE (0 << 14)
#define LINKMOVEU3_SPRITE_SIZE (2 << 14)
#define LINKMOVEU3_ID 768

#define LINKMOVEU4_SPRITE_SHAPE (0 << 14)
#define LINKMOVEU4_SPRITE_SIZE (2 << 14)
#define LINKMOVEU4_ID 800

#define LINKMOVEU5_SPRITE_SHAPE (0 << 14)
#define LINKMOVEU5_SPRITE_SIZE (2 << 14)
#define LINKMOVEU5_ID 832

#define LINKMOVEU6_SPRITE_SHAPE (0 << 14)
#define LINKMOVEU6_SPRITE_SIZE (2 << 14)
#define LINKMOVEU6_ID 864

#define LINKPOSE0_SPRITE_SHAPE (0 << 14)
#define LINKPOSE0_SPRITE_SIZE (2 << 14)
#define LINKPOSE0_ID 896

#define LINKSTRIKED0_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKED0_SPRITE_SIZE (2 << 14)
#define LINKSTRIKED0_ID 928

#define LINKSTRIKED1_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKED1_SPRITE_SIZE (2 << 14)
#define LINKSTRIKED1_ID 960

#define LINKSTRIKED2_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKED2_SPRITE_SIZE (2 << 14)
#define LINKSTRIKED2_ID 992

#define LINKSTRIKED3_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKED3_SPRITE_SIZE (2 << 14)
#define LINKSTRIKED3_ID 1024

#define LINKSTRIKED4_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKED4_SPRITE_SIZE (2 << 14)
#define LINKSTRIKED4_ID 1056

#define LINKSTRIKED5_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKED5_SPRITE_SIZE (2 << 14)
#define LINKSTRIKED5_ID 1088

#define LINKSTRIKEF0_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEF0_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEF0_ID 1120

#define LINKSTRIKEF1_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEF1_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEF1_ID 1152

#define LINKSTRIKEF2_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEF2_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEF2_ID 1184

#define LINKSTRIKEF3_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEF3_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEF3_ID 1216

#define LINKSTRIKEF4_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEF4_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEF4_ID 1248

#define LINKSTRIKEF5_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEF5_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEF5_ID 1280

#define LINKSTRIKEF6_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEF6_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEF6_ID 1312

#define LINKSTRIKEF7_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEF7_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEF7_ID 1344

#define LINKSTRIKEF8_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEF8_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEF8_ID 1376

#define LINKSTRIKEU0_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEU0_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEU0_ID 1408

#define LINKSTRIKEU1_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEU1_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEU1_ID 1440

#define LINKSTRIKEU2_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEU2_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEU2_ID 1472

#define LINKSTRIKEU3_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEU3_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEU3_ID 1504

#define LINKSTRIKEU4_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEU4_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEU4_ID 1536

#define LINKSTRIKEU5_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEU5_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEU5_ID 1568

#define LINKSTRIKEU6_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEU6_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEU6_ID 1600

#define LINKSTRIKEU7_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEU7_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEU7_ID 1632

#define LINKSTRIKEU8_SPRITE_SHAPE (0 << 14)
#define LINKSTRIKEU8_SPRITE_SIZE (2 << 14)
#define LINKSTRIKEU8_ID 1664

#define POPO0_SPRITE_SHAPE (0 << 14)
#define POPO0_SPRITE_SIZE (2 << 14)
#define POPO0_ID 1696

#define POPO1_SPRITE_SHAPE (0 << 14)
#define POPO1_SPRITE_SIZE (2 << 14)
#define POPO1_ID 1728

#define POPO2_SPRITE_SHAPE (0 << 14)
#define POPO2_SPRITE_SIZE (2 << 14)
#define POPO2_ID 1760

#define SWORD_SPRITE_SHAPE (2 << 14)
#define SWORD_SPRITE_SIZE (0 << 14)
#define SWORD_ID 1792

#define TRIFORCE_SPRITE_SHAPE (2 << 14)
#define TRIFORCE_SPRITE_SIZE (3 << 14)
#define TRIFORCE_ID 1796

#endif

