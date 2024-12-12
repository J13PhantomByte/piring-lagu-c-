#include <iostream>
#include <thread>
#include <chrono>

// Fungsi untuk menampilkan animasi piring lagu
void displayTurntableAnimation(int steps) {
    const char* frames[] = {"|", "/", "-", "\\"}; // Animasi putaran
    for (int i = 0; i < steps; ++i) {
        std::cout << "\rPiring Lagu: " << frames[i % 4] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::cout << "\rPiring Lagu selesai berputar!      \n";
}

// Fungsi untuk memutar lagu sederhana
void playMusic() {
    std::cout << "Memutar lagu: \"Twinkle Twinkle Little Star\"" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    const char* lyrics[] = {
        "Twinkle, twinkle, little star,",
        "How I wonder what you are!",
        "Up above the world so high,",
        "Like a diamond in the sky.",
    };

    for (const auto& line : lyrics) {
        std::cout << line << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
}

int main() {
    std::cout << "Selamat datang di simulasi piring lagu!" << std::endl;

    // Jalankan animasi piring lagu dalam thread terpisah
    std::thread animationThread(displayTurntableAnimation, 20); // Animasi piring lagu
    playMusic();

    // Tunggu thread animasi selesai
    animationThread.join();

    std::cout << "Terima kasih telah menggunakan aplikasi ini!" << std::endl;
    return 0;
}
