/*
* libtcod 1.4.1
* Copyright (c) 2008,2009 J.C.Wilk
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * The name of J.C.Wilk may not be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY J.C.WILK ``AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL J.C.WILK BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _TCOD_PERLIN_H
#define _TCOD_PERLIN_H

typedef void *TCOD_noise_t;

#define TCOD_NOISE_MAX_OCTAVES			128	
#define TCOD_NOISE_MAX_DIMENSIONS		4
#define TCOD_NOISE_DEFAULT_HURST        0.5f
#define TCOD_NOISE_DEFAULT_LACUNARITY   2.0f

TCODLIB_API TCOD_noise_t TCOD_noise_new(int dimensions, float hurst, float lacunarity, TCOD_random_t random);
// basic perlin noise
TCODLIB_API float TCOD_noise_perlin( TCOD_noise_t noise, float *f );
// fractional brownian motion (fractal sum of perlin noises)
TCODLIB_API float TCOD_noise_fbm_perlin( TCOD_noise_t noise, float *f, float octaves );
// turbulence (fractal sum of abs(perlin noise) )
TCODLIB_API float TCOD_noise_turbulence_perlin( TCOD_noise_t noise, float *f, float octaves );
// simplex noise
TCODLIB_API float TCOD_noise_simplex( TCOD_noise_t noise, float *f );
// fractional brownian motion (fractal sum of simplex noises)
TCODLIB_API float TCOD_noise_fbm_simplex( TCOD_noise_t noise, float *f, float octaves );
// turbulence (fractal sum of abs(simplex noise) )
TCODLIB_API float TCOD_noise_turbulence_simplex( TCOD_noise_t noise, float *f, float octaves );
// wavelet noise
TCODLIB_API float TCOD_noise_wavelet (TCOD_noise_t noise, float *f);
// fractional brownian motion (fractal sum of wavelet noises)
TCODLIB_API float TCOD_noise_fbm_wavelet(TCOD_noise_t noise, float *f, float octaves);
// turbulence (fractal sum of abs(simplex noise) )
TCODLIB_API float TCOD_noise_turbulence_wavelet(TCOD_noise_t noise, float *f, float octaves);

TCODLIB_API void TCOD_noise_delete(TCOD_noise_t noise);

#endif
