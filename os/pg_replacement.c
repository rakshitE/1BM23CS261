#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fifo(int frames, int ref_len, int ref_string[]);
void lru(int frames, int ref_len, int ref_string[]);
void optimal(int frames, int ref_len, int ref_string[]);
void print_step(int step, int frames, int memory[], bool is_fault);

int main() {
    int frames, ref_len;

    printf("Enter the number of Frames: ");
    scanf("%d", &frames);

    printf("Enter the length of reference string: ");
    scanf("%d", &ref_len);

    int ref_string[ref_len];
    printf("Enter the reference string: ");
    for(int i = 0; i < ref_len; i++) {
        scanf("%d", &ref_string[i]);
    }

    printf("\nFIFO Page Replacement Process:\n");
    fifo(frames, ref_len, ref_string);

    printf("\nLRU Page Replacement Process:\n");
    lru(frames, ref_len, ref_string);

    printf("\nOptimal Page Replacement Process:\n");
    optimal(frames, ref_len, ref_string);

    return 0;
}

void fifo(int frames, int ref_len, int ref_string[]) {
    int memory[frames];
    int faults = 0;
    int pointer = 0; // FIFO pointer

    for(int i = 0; i < frames; i++) {
        memory[i] = -1; // Initialize memory as empty
    }

    for(int i = 0; i < ref_len; i++) {
        bool found = false;

        for(int j = 0; j < frames; j++) {
            if(memory[j] == ref_string[i]) {
                found = true;
                break;
            }
        }

        if(!found) {
            memory[pointer] = ref_string[i];
            pointer = (pointer + 1) % frames; 
            faults++;
            print_step(i + 1, frames, memory, true);
        } else {
            print_step(i + 1, frames, memory, false);
        }
    }

    printf("FIFO Page Faults: %d\n", faults);
}

void lru(int frames, int ref_len, int ref_string[]) {
    int memory[frames];
    int counter[frames]; 
    int faults = 0;

    for(int i = 0; i < frames; i++) {
        memory[i] = -1;
        counter[i] = 0;
    }

    for(int i = 0; i < ref_len; i++) {
        bool found = false;
        int pos = -1;

        for(int j = 0; j < frames; j++) {
            if(memory[j] == ref_string[i]) {
                found = true;
                pos = j;
                break;
            }
        }

        if(found) {
            counter[pos] = i + 1; 
            print_step(i + 1, frames, memory, false);
        } else {
            faults++;
            int lru_pos = 0;
            for(int j = 1; j < frames; j++) {
                if(counter[j] < counter[lru_pos]) {
                    lru_pos = j;
                }
            }

            memory[lru_pos] = ref_string[i];
            counter[lru_pos] = i + 1;
            print_step(i + 1, frames, memory, true);
        }
    }

    printf("LRU Page Faults: %d\n", faults);
}

void optimal(int frames, int ref_len, int ref_string[]) {
    int memory[frames];
    int faults = 0;

    for(int i = 0; i < frames; i++) {
        memory[i] = -1;
    }

    for(int i = 0; i < ref_len; i++) {
        bool found = false;

        for(int j = 0; j < frames; j++) {
            if(memory[j] == ref_string[i]) {
                found = true;
                break;
            }
        }

        if(found) {
            print_step(i + 1, frames, memory, false);
        } else {
            faults++;
            int free_pos = -1;
            for(int j = 0; j < frames; j++) {
                if(memory[j] == -1) {
                    free_pos = j;
                    break;
                }
            }

            if(free_pos != -1) {
                memory[free_pos] = ref_string[i];
                print_step(i + 1, frames, memory, true);
            } else {
                int replace_pos = -1;
                int farthest = i;

                for(int j = 0; j < frames; j++) {
                    int k;
                    for(k = i + 1; k < ref_len; k++) {
                        if(memory[j] == ref_string[k]) {
                            if(k > farthest) {
                                farthest = k;
                                replace_pos = j;
                            }
                            break;
                        }
                    }

                    if(k == ref_len) {
                        replace_pos = j;
                        break;
                    }
                }

                memory[replace_pos] = ref_string[i];
                print_step(i + 1, frames, memory, true);
            }
        }
    }

    printf("Optimal Page Faults: %d\n", faults);
}

void print_step(int step, int frames, int memory[], bool is_fault) {
    printf("PF No. %d: ", step);

    for(int i = 0; i < frames; i++) {
        if(memory[i] != -1) {
            printf("%d ", memory[i]);
        } else {
            printf("- ");
        }
    }

    if(is_fault) {
        printf("\n");
    } else {
        printf("\n");
    }
}
