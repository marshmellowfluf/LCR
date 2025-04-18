#include <iostream>

#ifndef GFX_H
#define GFX_H

const int WIDTH_L_SIDE = 16;
const int HEIGHT_L_SIDE = 16;
const unsigned char GFX_L_SIDE[WIDTH_L_SIDE][HEIGHT_L_SIDE] = { 
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

const std::string TITLE_CARD[20] = 
{
"                                                                                                    ",
"            \6\6\6\6\6\6\6\6                                                                                ",
"            \6\6\6\6\6\6\6\6                                \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4                                 ",
"            \6\6\6\6\6\6\6\6                                \4\4\4\4\4\4\4\4      \4\4\4                               ",
"            \6\6\6\6\6\6\6\6                 \5\5\5\5\5\5\5\5\5\5\5    \4\4\4\4\4\4\4\4        \4\4                              ",
"            \6\6\6\6\6\6\6\6               \5\5\5\5\5\5\5     \5\5   \4\4\4\4\4\4\4\4        \4\4                              ",
"            \6\6\6\6\6\6\6\6             \5\5\5\5\5\5\5            \4\4\4\4\4\4\4\4        \4\4                              ",
"            \6\6\6\6\6\6\6\6             \5\5\5\5\5\5\5            \4\4\4\4\4\4\4\4       \4\4                               ",
"            \6\6\6\6\6\6\6\6            \5\5\5\5\5\5\5\5            \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4                                ",
"            \6\6\6\6\6\6\6\6            \5\5\5\5\5\5\5\5            \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4                                 ",
"            \6\6\6\6\6\6\6\6            \5\5\5\5\5\5\5\5            \4\4\4\4\4\4\4\4     \4\4\4                                ",
"            \6\6\6\6\6\6\6\6            \5\5\5\5\5\5\5\5            \4\4\4\4\4\4\4\4      \4\4\4                               ",
"            \6\6\6\6\6\6\6\6            \5\5\5\5\5\5\5\5            \4\4\4\4\4\4\4\4       \4\4\4                              ",
"            \6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6    \5\5\5\5\5\5\5            \4\4\4\4\4\4\4\4        \4\4\4                             ",
"                                 \5\5\5\5\5\5\5            \4\4\4\4\4\4\4\4         \4\4\4                            ",
"                                   \5\5\5\5\5\5\5     \5\5                                                   ",
"                                     \5\5\5\5\5\5\5\5\5\5\5                                                    ",
"                                                                                                    ",
"                                                                                                    ",
"                                                                                                    " };

#endif