@ECHO OFF

md %~1
cd %~1

md "algem"
cd "algem"

echo �������� ��������� �������� >> readme.txt
echo ������ �������: 20.09 >> readme.txt
cd..

md "matanaliz"
cd "matanaliz"

echo ��������� �������� ���������� >> readme.txt
echo ������ �������: 20.09 >> readme.txt
cd..

md "op"
cd "op"

echo ������� ������ ������������ >> readme.txt
echo ������ �������: 21.09 >> readme.txt
cd..

md "diskretka"
cd "diskretka"

echo �������� ������� ������� >> readme.txt
echo ������ �������: 24.09 >> readme.txt
cd..
cd..

copy op.bat semest1
copy algem.bat semest1

