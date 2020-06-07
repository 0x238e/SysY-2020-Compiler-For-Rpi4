Failed to load passes from '../build/libEmitAsm.so'. Request ignored.
Expected<T> must be checked before access or destruction.
Unchecked Expected<T> contained error:
Could not load library '../build/libEmitAsm.so': ../build/libEmitAsm.so: Can't open: 找不到指定的模块。  (0x7E)LLVMSymbolizer: error reading file: 'ucrtbase.pdb': LLVM was not compiled with support for DIA. This usually means that you are not using MSVC, or your Visual Studio installation is corrupt.
LLVMSymbolizer: error reading file: 'kernel32.pdb': LLVM was not compiled with support for DIA. This usually means that you are not using MSVC, or your Visual Studio installation is corrupt.
LLVMSymbolizer: error reading file: 'ntdll.pdb': LLVM was not compiled with support for DIA. This usually means that you are not using MSVC, or your Visual Studio installation is corrupt.
#0 0x00007ff6cec57485 (G:\Documents\llvm\build\Release\bin\opt.exe+0xdb7485)
#1 0x00007ffeda7561e1 (C:\WINDOWS\System32\ucrtbase.dll+0x761e1)
#2 0x00007ffeda7571e1 (C:\WINDOWS\System32\ucrtbase.dll+0x771e1)
#3 0x00007ff6cdeef7c1 (G:\Documents\llvm\build\Release\bin\opt.exe+0x4f7c1)
#4 0x00007ff6cdef3cc1 (G:\Documents\llvm\build\Release\bin\opt.exe+0x53cc1)
#5 0x00007ff6cdefda32 (G:\Documents\llvm\build\Release\bin\opt.exe+0x5da32)
#6 0x00007ff6cf1dce0c (G:\Documents\llvm\build\Release\bin\opt.exe+0x133ce0c)
#7 0x00007ffedaa79784 (C:\WINDOWS\System32\KERNEL32.DLL+0x19784)
#8 0x00007ffedc9396a1 (C:\WINDOWS\SYSTEM32\ntdll.dll+0x96a1)
