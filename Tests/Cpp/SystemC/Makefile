INCLUDE=/home/aditya/Downloads/systemc-2.3
INCLUDE_LIB=${INCLUDE}/lib-linux64
INCLUDE_HDR=${INCLUDE}/include
CPP_FLAGS=-shared -fPIC

all:
	g++ ${CPP_FLAGS} hello.cpp -I ${INCLUDE_HDR} -L${INCLUDE_LIB} -lsystemc-2.3.0

clean:
	rm -rf a.out

cleancore:
	rm -rf vgcore*
