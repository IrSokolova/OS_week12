#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>

int main(){
        struct input_event event;
	struct input_event event1;
	struct input_event event2;

        int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd",O_RDONLY);
        read(fd, &event1, sizeof(event1));
	read(fd, &event2, sizeof(event2));
	while (1){
                if (fd!=-1){
                        read(fd, &event, sizeof(event));
			if (event2.value==2 && event.value==2 && event2.code==25 && event.code==18){
			printf("I passed the Exam!\n");
			}
			if (event2.value==2 && event.value==2 && event2.code==18 && event.code==25){
                        printf("I passed the Exam!\n");
                        }
			if (event1.value==2 && event2.value==2 && event.value==2 && event1.code==46 && event2.code==30 && event.code==25){
			printf("Get some cappuccino!\n");
			}
			if (event2.value==2 && event.value==2 && event2.code==24 && event.code == 31){
                        printf("Operating systems\n");
                        }
                        if (event2.value==2 && event.value==2 && event2.code==31 && event.code==24){
                        printf("Operating systems\n");
                        }
			if (event2.value==2){
			event1=event2;
			}
			if (event.value==2){
			event2=event;
			}

                }
        }
}
