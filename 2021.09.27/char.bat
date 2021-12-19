@echo off
chcp 1251 > nul

for /l %%i in (33,1,255) do (
	call :symb %%i
)

exit /b

---

:symb
setlocal
cmd /c exit %1
echo %1 "%=exitcodeAscii%"
exit /b
