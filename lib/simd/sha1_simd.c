/***
* Copyright 2017 Marc Stevens <marc@marc-stevens.nl>, Dan Shumow (danshu@microsoft.com)
* Distributed under the MIT Software License.
* See accompanying file LICENSE.txt or copy at
* https://opensource.org/licenses/MIT
***/

#include <stdint.h>

#define CNT_SHA1_DVS (14)
uint32_t sha1_dvs_simd[80][CNT_SHA1_DVS] = 
{
	{ 0x2c000010, 0xb800000a, 0x18000000, 0x0800000c, 0xe8000000, 0xe000002a, 0x60000000, 0x2400001c, 0xb400001c, 0xc0000010, 0x0c000002, 0xcc000014, 0x0400001c, 0x2600001a},
	{ 0xf4000014, 0xc8000010, 0xb800000a, 0x18000000, 0x0800000c, 0x20000043, 0xe000002a, 0xec000014, 0x3c000004, 0xb400001c, 0xc0000010, 0x0c000002, 0xcc000014, 0x00000010},
	{ 0xb4000008, 0x2c000010, 0xc8000010, 0xb800000a, 0x18000000, 0xb0000040, 0x20000043, 0x0c000002, 0xbc00001a, 0x3c000004, 0xb400001c, 0xc0000010, 0x0c000002, 0x0400001c},
	{ 0x08000000, 0xf4000014, 0x2c000010, 0xc8000010, 0xb800000a, 0xd0000053, 0xb0000040, 0xc0000010, 0x20000010, 0xbc00001a, 0x3c000004, 0xb400001c, 0xc0000010, 0xcc000014},
	{ 0x9800000c, 0xb4000008, 0xf4000014, 0x2c000010, 0xc8000010, 0xd0000022, 0xd0000053, 0xb400001c, 0x2400001c, 0x20000010, 0xbc00001a, 0x3c000004, 0xb400001c, 0x0c000002},
	{ 0xd8000010, 0x08000000, 0xb4000008, 0xf4000014, 0x2c000010, 0x20000000, 0xd0000022, 0x2c000004, 0xec000014, 0x2400001c, 0x20000010, 0xbc00001a, 0x3c000004, 0xc0000010},
	{ 0x08000010, 0x9800000c, 0x08000000, 0xb4000008, 0xf4000014, 0x60000032, 0x20000000, 0xbc000018, 0x0c000002, 0xec000014, 0x2400001c, 0x20000010, 0xbc00001a, 0xb400001c},
	{ 0xb8000010, 0xd8000010, 0x9800000c, 0x08000000, 0xb4000008, 0x60000043, 0x60000032, 0xb0000010, 0xc0000010, 0x0c000002, 0xec000014, 0x2400001c, 0x20000010, 0x3c000004},
	{ 0x98000000, 0x08000010, 0xd8000010, 0x9800000c, 0x08000000, 0x20000040, 0x60000043, 0x0000000c, 0xb400001c, 0xc0000010, 0x0c000002, 0xec000014, 0x2400001c, 0xbc00001a},
	{ 0x60000000, 0xb8000010, 0x08000010, 0xd8000010, 0x9800000c, 0xe0000042, 0x20000040, 0xb8000010, 0x2c000004, 0xb400001c, 0xc0000010, 0x0c000002, 0xec000014, 0x20000010},
	{ 0x00000008, 0x98000000, 0xb8000010, 0x08000010, 0xd8000010, 0x60000002, 0xe0000042, 0x08000018, 0xbc000018, 0x2c000004, 0xb400001c, 0xc0000010, 0x0c000002, 0x2400001c},
	{ 0xc0000000, 0x60000000, 0x98000000, 0xb8000010, 0x08000010, 0x80000001, 0x60000002, 0x78000010, 0xb0000010, 0xbc000018, 0x2c000004, 0xb400001c, 0xc0000010, 0xec000014},
	{ 0x90000014, 0x00000008, 0x60000000, 0x98000000, 0xb8000010, 0x00000020, 0x80000001, 0x08000014, 0x0000000c, 0xb0000010, 0xbc000018, 0x2c000004, 0xb400001c, 0x0c000002},
	{ 0x10000010, 0xc0000000, 0x00000008, 0x60000000, 0x98000000, 0x00000003, 0x00000020, 0x70000010, 0xb8000010, 0x0000000c, 0xb0000010, 0xbc000018, 0x2c000004, 0xc0000010},
	{ 0xb8000014, 0x90000014, 0xc0000000, 0x00000008, 0x60000000, 0x40000052, 0x00000003, 0xb800001c, 0x08000018, 0xb8000010, 0x0000000c, 0xb0000010, 0xbc000018, 0xb400001c},
	{ 0x28000000, 0x10000010, 0x90000014, 0xc0000000, 0x00000008, 0x40000040, 0x40000052, 0xe8000000, 0x78000010, 0x08000018, 0xb8000010, 0x0000000c, 0xb0000010, 0x2c000004},
	{ 0x20000010, 0xb8000014, 0x10000010, 0x90000014, 0xc0000000, 0xe0000052, 0x40000040, 0xb0000004, 0x08000014, 0x78000010, 0x08000018, 0xb8000010, 0x0000000c, 0xbc000018},
	{ 0x48000000, 0x28000000, 0xb8000014, 0x10000010, 0x90000014, 0xa0000000, 0xe0000052, 0x58000010, 0x70000010, 0x08000014, 0x78000010, 0x08000018, 0xb8000010, 0xb0000010},
	{ 0x08000018, 0x20000010, 0x28000000, 0xb8000014, 0x10000010, 0x80000040, 0xa0000000, 0xb000000c, 0xb800001c, 0x70000010, 0x08000014, 0x78000010, 0x08000018, 0x0000000c},
	{ 0x60000000, 0x48000000, 0x20000010, 0x28000000, 0xb8000014, 0x20000001, 0x80000040, 0x48000000, 0xe8000000, 0xb800001c, 0x70000010, 0x08000014, 0x78000010, 0xb8000010},
	{ 0x90000010, 0x08000018, 0x48000000, 0x20000010, 0x28000000, 0x20000060, 0x20000001, 0xb0000000, 0xb0000004, 0xe8000000, 0xb800001c, 0x70000010, 0x08000014, 0x08000018},
	{ 0xf0000010, 0x60000000, 0x08000018, 0x48000000, 0x20000010, 0x80000001, 0x20000060, 0xb8000010, 0x58000010, 0xb0000004, 0xe8000000, 0xb800001c, 0x70000010, 0x78000010},
	{ 0x90000008, 0x90000010, 0x60000000, 0x08000018, 0x48000000, 0x40000042, 0x80000001, 0x98000010, 0xb000000c, 0x58000010, 0xb0000004, 0xe8000000, 0xb800001c, 0x08000014},
	{ 0xc0000000, 0xf0000010, 0x90000010, 0x60000000, 0x08000018, 0xc0000043, 0x40000042, 0xa0000000, 0x48000000, 0xb000000c, 0x58000010, 0xb0000004, 0xe8000000, 0x70000010},
	{ 0x90000010, 0x90000008, 0xf0000010, 0x90000010, 0x60000000, 0x40000022, 0xc0000043, 0x00000000, 0xb0000000, 0x48000000, 0xb000000c, 0x58000010, 0xb0000004, 0xb800001c},
	{ 0xf0000010, 0xc0000000, 0x90000008, 0xf0000010, 0x90000010, 0x00000003, 0x40000022, 0x00000000, 0xb8000010, 0xb0000000, 0x48000000, 0xb000000c, 0x58000010, 0xe8000000},
	{ 0xb0000008, 0x90000010, 0xc0000000, 0x90000008, 0xf0000010, 0x40000042, 0x00000003, 0x20000000, 0x98000010, 0xb8000010, 0xb0000000, 0x48000000, 0xb000000c, 0xb0000004},
	{ 0x40000000, 0xf0000010, 0x90000010, 0xc0000000, 0x90000008, 0xc0000043, 0x40000042, 0x80000000, 0xa0000000, 0x98000010, 0xb8000010, 0xb0000000, 0x48000000, 0x58000010},
	{ 0x90000000, 0xb0000008, 0xf0000010, 0x90000010, 0xc0000000, 0xc0000022, 0xc0000043, 0x00000010, 0x00000000, 0xa0000000, 0x98000010, 0xb8000010, 0xb0000000, 0xb000000c},
	{ 0xf0000010, 0x40000000, 0xb0000008, 0xf0000010, 0x90000010, 0x00000001, 0xc0000022, 0x00000000, 0x00000000, 0x00000000, 0xa0000000, 0x98000010, 0xb8000010, 0x48000000},
	{ 0x90000018, 0x90000000, 0x40000000, 0xb0000008, 0xf0000010, 0x40000002, 0x00000001, 0x20000010, 0x20000000, 0x00000000, 0x00000000, 0xa0000000, 0x98000010, 0xb0000000},
	{ 0x60000000, 0xf0000010, 0x90000000, 0x40000000, 0xb0000008, 0xc0000043, 0x40000002, 0x20000000, 0x80000000, 0x20000000, 0x00000000, 0x00000000, 0xa0000000, 0xb8000010},
	{ 0x90000010, 0x90000018, 0xf0000010, 0x90000000, 0x40000000, 0x40000062, 0xc0000043, 0x00000010, 0x00000010, 0x80000000, 0x20000000, 0x00000000, 0x00000000, 0x98000010},
	{ 0x90000010, 0x60000000, 0x90000018, 0xf0000010, 0x90000000, 0x80000001, 0x40000062, 0x60000000, 0x00000000, 0x00000010, 0x80000000, 0x20000000, 0x00000000, 0xa0000000},
	{ 0x90000000, 0x90000010, 0x60000000, 0x90000018, 0xf0000010, 0x40000042, 0x80000001, 0x00000018, 0x20000010, 0x00000000, 0x00000010, 0x80000000, 0x20000000, 0x00000000},
	{ 0x80000000, 0x90000010, 0x90000010, 0x60000000, 0x90000018, 0x40000042, 0x40000042, 0xe0000000, 0x20000000, 0x20000010, 0x00000000, 0x00000010, 0x80000000, 0x00000000},
	{ 0x00000010, 0x90000000, 0x90000010, 0x90000010, 0x60000000, 0x40000002, 0x40000042, 0x90000000, 0x00000010, 0x20000000, 0x20000010, 0x00000000, 0x00000010, 0x20000000},
	{ 0xa0000000, 0x80000000, 0x90000000, 0x90000010, 0x90000010, 0x00000002, 0x40000002, 0x30000010, 0x60000000, 0x00000010, 0x20000000, 0x20000010, 0x00000000, 0x80000000},
	{ 0x20000000, 0x00000010, 0x80000000, 0x90000000, 0x90000010, 0x00000040, 0x00000002, 0xb0000000, 0x00000018, 0x60000000, 0x00000010, 0x20000000, 0x20000010, 0x00000010},
	{ 0xa0000000, 0xa0000000, 0x00000010, 0x80000000, 0x90000000, 0x80000002, 0x00000040, 0x20000000, 0xe0000000, 0x00000018, 0x60000000, 0x00000010, 0x20000000, 0x00000000},
	{ 0x20000010, 0x20000000, 0xa0000000, 0x00000010, 0x80000000, 0x80000000, 0x80000002, 0x20000000, 0x90000000, 0xe0000000, 0x00000018, 0x60000000, 0x00000010, 0x20000010},
	{ 0x00000000, 0xa0000000, 0x20000000, 0xa0000000, 0x00000010, 0x80000002, 0x80000000, 0xa0000000, 0x30000010, 0x90000000, 0xe0000000, 0x00000018, 0x60000000, 0x20000000},
	{ 0x20000010, 0x20000010, 0xa0000000, 0x20000000, 0xa0000000, 0x80000040, 0x80000002, 0x00000010, 0xb0000000, 0x30000010, 0x90000000, 0xe0000000, 0x00000018, 0x00000010},
	{ 0x20000000, 0x00000000, 0x20000010, 0xa0000000, 0x20000000, 0x00000000, 0x80000040, 0x80000000, 0x20000000, 0xb0000000, 0x30000010, 0x90000000, 0xe0000000, 0x60000000},
	{ 0x00000010, 0x20000010, 0x00000000, 0x20000010, 0xa0000000, 0x80000040, 0x00000000, 0x20000000, 0x20000000, 0x20000000, 0xb0000000, 0x30000010, 0x90000000, 0x00000018},
	{ 0x20000000, 0x20000000, 0x20000010, 0x00000000, 0x20000010, 0x80000000, 0x80000040, 0x20000000, 0xa0000000, 0x20000000, 0x20000000, 0xb0000000, 0x30000010, 0xe0000000},
	{ 0x00000010, 0x00000010, 0x20000000, 0x20000010, 0x00000000, 0x00000040, 0x80000000, 0x20000000, 0x00000010, 0xa0000000, 0x20000000, 0x20000000, 0xb0000000, 0x90000000},
	{ 0xa0000000, 0x20000000, 0x00000010, 0x20000000, 0x20000010, 0x80000000, 0x00000040, 0x80000000, 0x80000000, 0x00000010, 0xa0000000, 0x20000000, 0x20000000, 0x30000010},
	{ 0x00000000, 0x00000010, 0x20000000, 0x00000010, 0x20000000, 0x00000040, 0x80000000, 0x00000010, 0x20000000, 0x80000000, 0x00000010, 0xa0000000, 0x20000000, 0xb0000000},
	{ 0x20000000, 0xa0000000, 0x00000010, 0x20000000, 0x00000010, 0x80000002, 0x00000040, 0x00000000, 0x20000000, 0x20000000, 0x80000000, 0x00000010, 0xa0000000, 0x20000000},
	{ 0x20000000, 0x00000000, 0xa0000000, 0x00000010, 0x20000000, 0x00000000, 0x80000002, 0x20000010, 0x20000000, 0x20000000, 0x20000000, 0x80000000, 0x00000010, 0x20000000},
	{ 0x00000000, 0x20000000, 0x00000000, 0xa0000000, 0x00000010, 0x80000000, 0x00000000, 0xa0000000, 0x80000000, 0x20000000, 0x20000000, 0x20000000, 0x80000000, 0xa0000000},
	{ 0x00000000, 0x20000000, 0x20000000, 0x00000000, 0xa0000000, 0x80000000, 0x80000000, 0x00000000, 0x00000010, 0x80000000, 0x20000000, 0x20000000, 0x20000000, 0x00000010},
	{ 0x00000000, 0x00000000, 0x20000000, 0x20000000, 0x00000000, 0x00000000, 0x80000000, 0x20000000, 0x00000000, 0x00000010, 0x80000000, 0x20000000, 0x20000000, 0x80000000},
	{ 0x00000000, 0x00000000, 0x00000000, 0x20000000, 0x20000000, 0x00000000, 0x00000000, 0x20000000, 0x20000010, 0x00000000, 0x00000010, 0x80000000, 0x20000000, 0x20000000},
	{ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x20000000, 0x00000000, 0x00000000, 0x00000000, 0xa0000000, 0x20000010, 0x00000000, 0x00000010, 0x80000000, 0x20000000},
	{ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xa0000000, 0x20000010, 0x00000000, 0x00000010, 0x20000000},
	{ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x20000000, 0x00000000, 0xa0000000, 0x20000010, 0x00000000, 0x80000000},
	{ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x20000000, 0x20000000, 0x00000000, 0xa0000000, 0x20000010, 0x00000010},
	{ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x20000000, 0x20000000, 0x00000000, 0xa0000000, 0x00000000},
	{ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x20000000, 0x20000000, 0x00000000, 0x20000010},
	{ 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x20000000, 0x20000000, 0xa0000000},
	{ 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x20000000, 0x00000000},
	{ 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x20000000},
	{ 0x40000002, 0x00000020, 0x00000001, 0x00000000, 0x00000000, 0x00000080, 0x00000004, 0x40000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x20000000},
	{ 0x40000040, 0x00000001, 0x00000020, 0x00000001, 0x00000000, 0x00000004, 0x00000080, 0x40000041, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{ 0x40000002, 0x40000002, 0x00000001, 0x00000020, 0x00000001, 0x00000009, 0x00000004, 0x40000022, 0x00000020, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{ 0x80000004, 0x40000040, 0x40000002, 0x00000001, 0x00000020, 0x00000101, 0x00000009, 0x80000005, 0x00000001, 0x00000020, 0x00000001, 0x00000000, 0x00000000, 0x00000000},
	{ 0x80000080, 0x40000002, 0x40000040, 0x40000002, 0x00000001, 0x00000009, 0x00000101, 0xc0000082, 0x40000002, 0x00000001, 0x00000020, 0x00000001, 0x00000000, 0x00000000},
	{ 0x80000006, 0x80000004, 0x40000002, 0x40000040, 0x40000002, 0x00000012, 0x00000009, 0xc0000046, 0x40000041, 0x40000002, 0x00000001, 0x00000020, 0x00000001, 0x00000000},
	{ 0x00000049, 0x80000080, 0x80000004, 0x40000002, 0x40000040, 0x00000202, 0x00000012, 0x4000004b, 0x40000022, 0x40000041, 0x40000002, 0x00000001, 0x00000020, 0x00000000},
	{ 0x00000103, 0x80000006, 0x80000080, 0x80000004, 0x40000002, 0x0000001a, 0x00000202, 0x80000107, 0x80000005, 0x40000022, 0x40000041, 0x40000002, 0x00000001, 0x00000001},
	{ 0x80000009, 0x00000049, 0x80000006, 0x80000080, 0x80000004, 0x00000124, 0x0000001a, 0x00000089, 0xc0000082, 0x80000005, 0x40000022, 0x40000041, 0x40000002, 0x00000020},
	{ 0x80000012, 0x00000103, 0x00000049, 0x80000006, 0x80000080, 0x0000040c, 0x00000124, 0x00000014, 0xc0000046, 0xc0000082, 0x80000005, 0x40000022, 0x40000041, 0x00000001},
	{ 0x80000202, 0x80000009, 0x00000103, 0x00000049, 0x80000006, 0x00000026, 0x0000040c, 0x8000024b, 0x4000004b, 0xc0000046, 0xc0000082, 0x80000005, 0x40000022, 0x40000002},
	{ 0x00000018, 0x80000012, 0x80000009, 0x00000103, 0x00000049, 0x0000004a, 0x00000026, 0x0000011b, 0x80000107, 0x4000004b, 0xc0000046, 0xc0000082, 0x80000005, 0x40000041},
	{ 0x00000164, 0x80000202, 0x80000012, 0x80000009, 0x00000103, 0x0000080a, 0x0000004a, 0x8000016d, 0x00000089, 0x80000107, 0x4000004b, 0xc0000046, 0xc0000082, 0x40000022},
	{ 0x00000408, 0x00000018, 0x80000202, 0x80000012, 0x80000009, 0x00000060, 0x0000080a, 0x8000041a, 0x00000014, 0x00000089, 0x80000107, 0x4000004b, 0xc0000046, 0x80000005},
	{ 0x800000e6, 0x00000164, 0x00000018, 0x80000202, 0x80000012, 0x00000590, 0x00000060, 0x000002e4, 0x8000024b, 0x00000014, 0x00000089, 0x80000107, 0x4000004b, 0xc0000082},
	{ 0x8000004c, 0x00000408, 0x00000164, 0x00000018, 0x80000202, 0x00001020, 0x00000590, 0x80000054, 0x0000011b, 0x8000024b, 0x00000014, 0x00000089, 0x80000107, 0xc0000046}
};

/*
static void sha1_process(SHA1_CTX* ctx, const uint32_t block[16])
{
	ctx->ihv1[0] = ctx->ihv[0];
	ctx->ihv1[1] = ctx->ihv[1];
	ctx->ihv1[2] = ctx->ihv[2];
	ctx->ihv1[3] = ctx->ihv[3];
	ctx->ihv1[4] = ctx->ihv[4];

	sha1_compression_states(ctx->ihv, block, ctx->m1, ctx->states);

	if (ctx->detect_coll)
	{
		for (i = 0; sha1_dvs[i].dvType != 0; ++i)
		{
			for (j = 0; j < 80; ++j)
				ctx->m2[j] = ctx->m1[j] ^ sha1_dvs[i].dm[j];

			sha1_recompression_step(sha1_dvs[i].testt, ctx->ihv2, ihvtmp, ctx->m2, ctx->states[sha1_dvs[i].testt]);

			// to verify SHA-1 collision detection code with collisions for reduced-step SHA-1 
			if ((0 == ((ihvtmp[0] ^ ctx->ihv[0]) | (ihvtmp[1] ^ ctx->ihv[1]) | (ihvtmp[2] ^ ctx->ihv[2]) | (ihvtmp[3] ^ ctx->ihv[3]) | (ihvtmp[4] ^ ctx->ihv[4])))
				|| (ctx->reduced_round_coll && 0==((ctx->ihv1[0] ^ ctx->ihv2[0]) | (ctx->ihv1[1] ^ ctx->ihv2[1]) | (ctx->ihv1[2] ^ ctx->ihv2[2]) | (ctx->ihv1[3] ^ ctx->ihv2[3]) | (ctx->ihv1[4] ^ ctx->ihv2[4]))))
			{
				ctx->found_collision = 1;

				if (ctx->safe_hash)
				{
					sha1_compression_W(ctx->ihv, ctx->m1);
					sha1_compression_W(ctx->ihv, ctx->m1);
				}
			}
		}
	}
}
*/
