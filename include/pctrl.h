/*=============================================================================
ttyrpld - TTY replay daemon
include/pctrl.h
  Copyright © Jan Engelhardt <jengelh [at] gmx de>, 2004 - 2006

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
  3. Redistributions of modified code that are made available only in binary
     form require sending a description to the ttyrpld project maintainer on
     what has been changed.
  4. Neither the names of the above-listed copyright holders nor the names of
     any contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

  NO WARRANTY. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT
  NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A
  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
  CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
=============================================================================*/
#ifndef TTYREPLAY_PCTRL_H
#define TTYREPLAY_PCTRL_H 1

#ifdef __cplusplus
extern "C" {
#endif

enum {
    PCTRL_NONE = 0,
    PCTRL_PREV,
    PCTRL_NEXT,
    PCTRL_EXIT,
    PCTRL_SKPACK,
    PCTRL_SKTIME,
};

struct pctrl_info {
    double factor;
    int sktype;
    long skval;
    unsigned char paused, brk, echo;
};

extern int pctrl_init(void);
extern void pctrl_exit(void);
extern void pctrl_activate(struct pctrl_info *);
extern void pctrl_deactivate(int);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TTYREPLAY_PCTRL_H

//=============================================================================
