#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define world_width 80
#define world_height 25

typedef struct cell_t_ {
    struct cell_t_ *neighbours[8];
    int on;
} cell_t;

typedef struct world_t_ {
    cell_t **array;
    int width;
    int height;
    void *mem;
} world_t;

void read_world(world_t *world);
int create_world(world_t *world, int width, int height);
void destroy_world(world_t *world);
void update_world(world_t *world);
void randomize_world(world_t *world, int seed_height, int seed_width);
void print_world(world_t *world);
void game_step(world_t* game_of_life);
void setup_curses(void);
int consume_all_input(void);
void init(void);

void print_world(world_t *world) {
    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x < world->width; x++) {
            printf("%c", (world->array[y][x]).on ? 'O' : ' ');
        }
        printf("\n");
    }
}

void read_world(world_t *world) {
    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x < world->width; x++) {
            char input;
            input = getchar();
            if (input == '1') {
                (world->array[y][x]).on = 1;
            } else if (input == '0') {
                (world->array[y][x]).on = 0;
            } else {
                x--;
            }
        }
    }
}

void randomize_world(world_t *world, int seed_height, int seed_width) {
    srand(time(NULL));
    for (int y = 0; y < world->height; y = y + seed_height) {
        for (int x = 0; x < world->width; x = x + seed_width) {
            (world->array[y][x]).on = rand() & 1;
        }
    }
}

void update_world(world_t *world) {
    int neighbours = 0;
    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x < world->width; x++, neighbours = 0) {
            for (int i = 0; i < 8; i++)
                if ((world->array[y][x].neighbours[i]) && ((world->array[y][x]).neighbours[i]->on & 1))
                    neighbours++;
            if ((neighbours < 2) || (neighbours > 3)) {
                (world->array[y][x]).on |= 2;
            } else if (neighbours == 3) {
                (world->array[y][x]).on |= 4;
            }
        }
    }
    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x < world->width; x++) {
            if (world->array[y][x].on & 4)
                world->array[y][x].on = 1;
            else if (world->array[y][x].on & 2)
                world->array[y][x].on = 0;
        }
    }
}

void destroy_world(world_t *world) {
    free(world->mem);
}

int create_world(world_t *world, int width, int height) {
    unsigned long base   = sizeof(cell_t *) * height;
    unsigned long rowlen = sizeof(cell_t)   * width;
    if (!(world->mem = calloc(base + (rowlen * height), 1))) {
        return 0;
    }
    world->array  = world->mem;
    world->width  = width;
    world->height = height;
    for (int i = 0; i < height; i++) {
        world->array[i] = world->mem + base + (i * rowlen);
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j != 0)
                (world->array[i][j]).neighbours[3] = &(world->array[i][j - 1]);
            if (i != 0)
                (world->array[i][j]).neighbours[1] = &(world->array[i - 1][j]);
            if (j != (width - 1))
                (world->array[i][j]).neighbours[4] = &(world->array[i][j + 1]);
            if (i != (height - 1))
                (world->array[i][j]).neighbours[6] = &(world->array[i + 1][j]);
            if ((i != 0) && (j != 0))
                (world->array[i][j]).neighbours[0] = &(world->array[i - 1][j - 1]);
            if ((i != (height - 1)) && (j != (width - 1)))
                (world->array[i][j]).neighbours[7] = &(world->array[i + 1][j + 1]);
            if ((i != (height - 1)) && (j != 0))
                (world->array[i][j]).neighbours[5] = &(world->array[i + 1][j - 1]);
            if ((i != 0) && (j != (width - 1)))
                (world->array[i][j]).neighbours[2] = &(world->array[i - 1][j + 1]);
        }
    }
    return 1;
}

void game_step(world_t* game_of_life) {
    print_world(game_of_life);
    while (1) {
        char status;
        status = getchar();
        if (status == 'q') {
            destroy_world(game_of_life);
            exit(-1);
        } else  {
            print_world(game_of_life);
            usleep(10000);
            update_world(game_of_life);
        }
    }
}

void init() {
    world_t game_of_life;
    if (create_world(&game_of_life, world_width, world_height)) {
        char type;
        int input_flag = 0;
        while (!input_flag) {
            type = getchar();
            if (type == 'g') {
                input_flag = 1;
            } else if (type == '2') {
                input_flag = 2;
            } else {
                printf("wrong command\n");
            }
        }
        if (input_flag == 1)
            randomize_world(&game_of_life, 1, 1);
        else
            read_world(&game_of_life);
        do {
            game_step(&game_of_life);
        } while (1);
    }
}

int main() {
    init();
    return 0;
}
