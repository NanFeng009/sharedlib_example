
EXECUTEABLE_OUTPUT_PATH = bin


all: ani

ani:
	if [ ! -d ${EXECUTEABLE_OUTPUT_PATH} ]; then mkdir -p ${EXECUTEABLE_OUTPUT_PATH}; fi
	make -C src

clean:
	make -C src clean
	rm -rf bin/*.o bin/ani bin/*.so
	rm -df bin
