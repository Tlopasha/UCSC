EX := ex2
all: run clean

LDFLAGS="-lpthread"

run: ${EX}
	time ./ex2 &
	-(sleep 3; ps -C ${EX} -L -o pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm)
	-(sleep 5; ps -C ${EX} -L -o pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm)
	-(sleep 5; ps -C ${EX} -L -o pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm)

ex1: ex1.c

clean:
	rm -f ex?
