@ECHO OFF

set a=500

:for
  set /a b=%a%*%a%
  set /a c=%b%%%1000000
  if %c%==269696 (
	echo %a%
	exit /b
 ) else (
	set /a a+=2
	goto :for
 )