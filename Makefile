all: genqr

genqr: qr.c test.c
	gcc $^ -lqrencode -o $@

clean:
	rm -rf genqr
