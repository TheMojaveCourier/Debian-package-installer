pkgmng: main.o PkgManager.o presskey.o Check.o
	g++ main.o PkgManager.o presskey.o Check.o -o /home/nikolas/Desktop/Pkg_installer/pkgmng

main.o: main.cc header.h
	g++ -c main.cc

PkgManager.o: PkgManager.cpp header.h
	g++ -c PkgManager.cpp
	
presskey.o: presskey.cpp header.h
	g++ -c presskey.cpp
	
Check.o: Check.cpp header.h
	g++ -c Check.cpp
clean:
	rm *.o pkgmng
