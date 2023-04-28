bin/stringMe: judgeJashanA2Main.o judgeJashanA2.o 
	gcc -Wall -std=c99 judgeJashanA2Main.o judgeJashanA2.o -o bin/stringMe

judgeJashanA2.o: src/judgeJashanA2.c  include/judgeJashanA2.h
	gcc -Wall -std=c99 -c src/judgeJashanA2.c

judgeJashanA2Main.o: src/judgeJashanA2Main.c include/judgeJashanA2.h
	gcc -Wall -std=c99 -c src/judgeJashanA2Main.c

clean:
	rm *.o bin/stringMe