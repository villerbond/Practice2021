@echo off

set level=0

:ask

if %1==0 goto m0
if %2==0 goto n0

:else
set /a n=%2-1
set /a level+=1
call :ask %1 %n%
set nn=%errorlevel%
set /a m=%1-1
call :ask %m% %nn%
set result=%errorlevel%
set /a level-=1
if %level%==0 (
    echo %result%
    goto :end
) else ( exit /b %result% )	
 
:m0

set /a n=%2+1
if %level%==0 (
    echo %n%
    goto :end
) else ( exit /b %n% )	

:n0

set /a m=%1-1
set /a level+=1
call :ask %m% 1
set result=%errorlevel%
set /a level-=1
if %level%==0 (
    echo %result%
    goto :end
) else ( exit /b %result% )

:end
exit /b
