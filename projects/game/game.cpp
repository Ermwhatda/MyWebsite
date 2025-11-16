#include <emscripten.h>
#include <emscripten/html5.h>

// Simple player struct
struct Player {
    float x, y;
};

// Global player
extern "C" {
    EMSCRIPTEN_KEEPALIVE
    Player player = {50.0f, 50.0f};

    // Move the player by dx, dy
    EMSCRIPTEN_KEEPALIVE
    void movePlayer(float dx, float dy) {
        player.x += dx;
        player.y += dy;
    }

    // Get player position
    EMSCRIPTEN_KEEPALIVE
    float getPlayerX() { return player.x; }

    EMSCRIPTEN_KEEPALIVE
    float getPlayerY() { return player.y; }
}

// Optional main function
int main() {
    emscripten_run_script("console.log('WASM game loaded!');");
    return 0;
}