let SessionLoad = 1
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd /mnt/c/Users/sjoerd/Documents/platformio/Projects/ledstrip
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +28 include/main.h
badd +45 src/main.cpp
badd +97 src/debug.cpp
badd +2 include/debug.h
badd +18 include/api.h
badd +47 src/api.cpp
badd +22 ~/.SpaceVim.d/init.toml
badd +29 .SpaceVim.d/tasks.toml
badd +1 ~/.SpaceVim.d/autorun
badd +1 ~/.SpaceVim.d/autorun/makefiletask.vim
badd +1 schoolprog.vim
badd +1 src/m
badd +19 makefile
badd +145 .pio/libdeps/esp32doit-devkit-v1/FastLED/src/fastspi.h
argglobal
%argdel
edit include/main.h
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 28 - ((27 * winheight(0) + 45) / 91)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
28
normal! 06|
tabedit src/debug.cpp
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 86 + 47) / 94)
exe '2resize ' . ((&lines * 4 + 47) / 94)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 82 - ((32 * winheight(0) + 43) / 86)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
82
normal! 046|
wincmd w
argglobal
enew
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
wincmd w
exe '1resize ' . ((&lines * 86 + 47) / 94)
exe '2resize ' . ((&lines * 4 + 47) / 94)
tabnext 2
if exists('s:wipebuf') && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 winminheight=1 winminwidth=1 shortmess=filnxtToOcsF
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
