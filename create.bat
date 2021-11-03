@ECHO OFF

md %~1
cd %~1

md "algem"
cd "algem"

echo Ведякова Анастасия Олеговна >> readme.txt
echo Начало занятий: 20.09 >> readme.txt
cd..

md "matanaliz"
cd "matanaliz"

echo Естафьева Виктория Викторовна >> readme.txt
echo Начало занятий: 20.09 >> readme.txt
cd..

md "op"
cd "op"

echo Погожев Сергей Владимирович >> readme.txt
echo Начало занятий: 21.09 >> readme.txt
cd..

md "diskretka"
cd "diskretka"

echo Максимов Алексей Юрьевич >> readme.txt
echo Начало занятий: 24.09 >> readme.txt
cd..
cd..

copy op.bat semest1
copy algem.bat semest1

