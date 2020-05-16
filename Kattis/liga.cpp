#include <cstdio>
#include <cstdlib>
using namespace std;

// Constants
#define MAX_STR_BUFFER 4
#define MAX_GAMES 100
#define MIN_GAMES 0
#define POINTS_PER_WIN 3
#define POINTS_PER_DRAW 1

// Fields
#define games values[0]
#define wins values[1]
#define draws values[2]
#define losses values[3]
#define points values[4]

int N, values[5], bitmask;
char s[MAX_STR_BUFFER];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        bitmask = 0;
        for (int j = 0; j < 5; j++) {
            scanf("%s", s);
            if (s[0] == '?') bitmask ^= 16 >> j;
            else values[j] = atoi(s);
        }
        switch (bitmask) {
            case 0b00000:
                break;
            case 0b00001:
                points = wins * POINTS_PER_WIN + draws * POINTS_PER_DRAW;
                break;
            case 0b00010:
                losses = games - wins - draws;
                break;
            case 0b00100:
                draws = games - wins - losses;
                break;
            case 0b01000:
                wins = games - draws - losses;
                break;
            case 0b10000:
                games = wins + draws + losses;
                break;
            case 0b00011:
                losses = games - wins - draws;
                points = wins * POINTS_PER_WIN + draws * POINTS_PER_DRAW;
                break;
            case 0b00101:
                draws = games - wins - losses;
                points = wins * POINTS_PER_WIN + draws * POINTS_PER_DRAW;
                break;
            case 0b01001:
                wins = games - draws - losses;
                points = wins * POINTS_PER_WIN + draws * POINTS_PER_DRAW;
                break;
            case 0b10001:
                games = wins + draws + losses;
                points = wins * POINTS_PER_WIN + draws * POINTS_PER_DRAW;
                break;
            case 0b00110:
                draws = (points - wins * POINTS_PER_WIN) / POINTS_PER_DRAW;
                losses = games - wins - draws;
                break;
            case 0b01010:
                wins = (points - draws * POINTS_PER_DRAW) / POINTS_PER_WIN;
                losses = games - wins - draws;
                break;
            case 0b10010:
                // Since there is a unique solution, wins + draws = MAX_GAMES
                games = MAX_GAMES;
                losses = 0;
                break;
            case 0b01100:
                draws = ((games - losses) * POINTS_PER_WIN - points)
                        / (POINTS_PER_WIN - POINTS_PER_DRAW);
                wins = games - draws - losses;
                break;
            case 0b10100:
                draws = (points - wins * POINTS_PER_WIN) / POINTS_PER_DRAW;
                games = wins + draws + losses;
                break;
            case 0b11000:
                wins = (points - draws * POINTS_PER_DRAW) / POINTS_PER_WIN;
                games = wins + draws + losses;
                break;
            case 0b00111:
                // Since there is a unique solution, games = wins
                draws = losses = 0;
                points = wins * POINTS_PER_WIN;
                break;
            case 0b01011:
                // Since there is a unique solution, games = draws
                wins = losses = 0;
                points = draws* POINTS_PER_DRAW;
                break;
            case 0b10011:
                // Since there is a unique solution, wins + draws = MAX_GAMES
                games = MAX_GAMES;
                losses = 0;
                points = wins * POINTS_PER_WIN + draws * POINTS_PER_DRAW;
                break;
            case 0b01101:
                // Since there is a unique solution, games = losses
                wins = draws = points = 0;
                break;
            case 0b10101:
                // Since there is a unique solution, wins + losses = MAX_GAMES
                games = MAX_GAMES;
                draws = 0;
                points = wins * POINTS_PER_WIN;
                break;
            case 0b11001:
                // Since there is a unique solution, draws + losses = MAX_GAMES
                games = MAX_GAMES;
                wins = 0;
                points = draws * POINTS_PER_DRAW;
                break;
            case 0b01110:
                wins = 0;
                while (true) {
                    draws = (points - wins * POINTS_PER_WIN) / POINTS_PER_DRAW;
                    losses = games - wins - draws;
                    if (losses >= 0) break;
                    else wins++;
                }
                break;
            case 0b10110:
                // Since there is a unique solution, wins + draws = MAX_GAMES
                games = MAX_GAMES;
                draws = games - wins;
                losses = 0;
                break;
            case 0b11010:
                // Since there is a unique solution, wins + draws = MAX_GAMES
                games = MAX_GAMES;
                wins = games - draws;
                losses = 0;
                break;
            case 0b11100:
                wins = 0;
                while (true) {
                    draws = (points - wins * POINTS_PER_WIN) / POINTS_PER_DRAW;
                    games = wins + draws + losses;
                    if (games <= MAX_GAMES) break;
                    else wins++;
                }
                break;
            case 0b01111:
                // Since there is a unique solution, games = 0
                wins = draws = losses = points = 0;
                break;
            case 0b10111:
                // Since there is a unique solution, wins = MAX_GAMES
                games = MAX_GAMES;
                draws = losses = 0;
                points = wins * POINTS_PER_WIN;
                break;
            case 0b11011:
                // Since there is a unique solution, draws = MAX_GAMES
                games = MAX_GAMES;
                wins = losses = 0;
                points = draws * POINTS_PER_DRAW;
                break;
            case 0b11101:
                // Since there is a unique solution, losses = MAX_GAMES
                games = MAX_GAMES;
                wins = draws = points = 0;
                break;
            case 0b11110:
                // Since there is a unique solution, games = MAX_GAMES && points >= 296
                games = MAX_GAMES;
                draws = (MAX_GAMES * POINTS_PER_WIN - points) / (POINTS_PER_WIN - POINTS_PER_DRAW);
                wins = games - draws;
                losses = 0;
                break;
        }
        printf("%d %d %d %d %d\n", games, wins, draws, losses, points);
    }
}