@echo on

@set SourceDir=Source
@set VSPath=Build
@set ProRoot=E:/Works/CPlus/GitWork/SystemLib/

@echo ---------------------generate project begin---------------------

md %VSPath%
cd %VSPath%
cmake -G"Visual Studio 16 2019" -A x64 %ProRoot%\%SourceDir% -DBINARY_DIR=%ProRoot%\%VSPath% -DCMAKE_CONFIGURATION_TYPES=Debug -DDEFAULT_CHARSET=utf8 -DDEFAULT_COLLATION=utf8_general_ci

@echo =====================generate project completed=====================

cd ..
pause
