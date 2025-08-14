#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdint.h>

/* Argument for arithmetic adder in FPGA */
struct calc_args {
	uint32_t arg1; // first argument
	uint32_t arg2; // second argument
};

/* cdev_gen_ioctl function in cdev.c catches below command */
#define QDMA_CDEV_IOCTL_CALC _IOW('q', 100, struct calc_args)
#define QDMA_CDEV_IOCTL_USER _IOW('q', 101, struct calc_args)
#define QDMA_CDEV_IOCTL_DRIVER _IOW('q', 102, struct calc_args)
#define QDMA_CDEV_IOCTL_ADDER _IOW('q', 103, struct calc_args)
#define QDMA_CDEV_IOCTL_DMA _IOW('q', 104, struct calc_args)

int main(int argc, char* argv[]) {
	int fd;
	struct calc_args args;
	int pnum;

	if(argc != 4) {
		printf("Usage: %s <arg1> <arg2> <problem_number>\n", argv[0]);
		return 1;
	}

	args.arg1 = atoi(argv[1]);
	args.arg2 = atoi(argv[2]);
	pnum = atoi(argv[3]);
	
	if(pnum < 1 || pnum > 5) {
		printf("Caution: problem number is an integer between 1 and 5.\n");
		return 1;
	}

	// open qdma driver
	fd = open("/dev/qdma0a000-MM-1", O_RDWR);
	
	if(fd < 0) {
		perror("open");
		return 1;
	}
	
	switch(pnum) {
		case 1:
			if(ioctl(fd, QDMA_CDEV_IOCTL_USER, &args) < 0) {
				perror("ioctl");
				close(fd);
				return 1;
			}
			break;
		case 2:
			if(ioctl(fd, QDMA_CDEV_IOCTL_DRIVER, &args) < 0) {
				perror("ioctl");
				close(fd);
				return 1;
			}
			break;
		case 3:
			if(ioctl(fd, QDMA_CDEV_IOCTL_ADDER, &args) < 0) {
				perror("ioctl");
				close(fd);
				return 1;
			}
			break;
		case 4:
			if(ioctl(fd, QDMA_CDEV_IOCTL_DMA, &args) < 0) {
				perror("ioctl");
				close(fd);
				return 1;
			}
			break;
		case 5:
			if(ioctl(fd, QDMA_CDEV_IOCTL_CALC, &args) < 0) {
				perror("ioctl");
				close(fd);
				return 1;
			}
			break;
	}

	close(fd);

	return 0;
}
