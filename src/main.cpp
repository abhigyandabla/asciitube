#include "tui.hpp"
#include <chrono>
#include <cmath>
#include <filesystem>
#include <iostream>
#include <thread>
#include <unistd.h>

// Frame rate for video
int frames_per_second = 10;

// File directory with stored frames
const std::filesystem::path frames_path = std::filesystem::u8path("frames/");

// Helper function to calculate # of frames in frames/ directory
std::size_t number_of_files_in_directory(std::filesystem::path path) {
  return (std::size_t)std::distance(std::filesystem::directory_iterator{path},
                                    std::filesystem::directory_iterator{});
}

// Function to covert frames image to ASCII art
void framesToTxt(int start, int end) {
  for (int i = start; i <= end; i++) {
    std::string i_as_string = std::__cxx11::to_string(i);
    int num_zeroes = 3 - i_as_string.size();

    for (int j = 0; j < num_zeroes; j++) {
      i_as_string = '0' + i_as_string;
    }

    std::string create_txtfile_call =
        "cd ascii && touch " + i_as_string + ".txt";
    std::string to_ascii_call = "jp2a --output=ascii/" + i_as_string +
                                ".txt frames/" + i_as_string + ".jpg";

    system(create_txtfile_call.c_str());
    system(to_ascii_call.c_str());
  }
}

int main() {
  // TODO: Get video from user, not local files

  tui();
  // Saving video frames to frames directory
  std::string video_to_frames_call =
      "ffmpeg -loglevel panic -i videos/man_walking.mp4 -r + " +
      std::__cxx11::to_string(frames_per_second) + "/1 frames/%03d.jpg";
  system(video_to_frames_call.c_str());

  // Finding number of frames to turn to txt
  int num_frames =
      number_of_files_in_directory(std::filesystem::absolute(frames_path));

  // Start time before conversions
  std::chrono::steady_clock::time_point begin =
      std::chrono::steady_clock::now();

  // Using 4 worker threads to concurrently change .jpg to ASCII art in .txt
  std::thread worker1(framesToTxt, 1, floor(num_frames / 4));
  std::thread worker2(framesToTxt, ceil(num_frames / 4), floor(num_frames / 2));
  std::thread worker3(framesToTxt, ceil(num_frames / 2),
                      floor(3 * num_frames / 4));
  std::thread worker4(framesToTxt, ceil(3 * num_frames / 4), floor(num_frames));

  // Waiting for worker threads to finish
  worker1.join();
  worker2.join();
  worker3.join();
  worker4.join();

  // End time after conversions
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  // Displaying each frame one by one
  for (int i = 1; i <= num_frames; i++) {
    std::string i_as_string = std::__cxx11::to_string(i);
    int num_zeroes = 3 - i_as_string.size();

    for (int j = 0; j < num_zeroes; j++) {
      i_as_string = '0' + i_as_string;
    }

    std::string print_output_call = "cat ascii/" + i_as_string + ".txt";

    system(print_output_call.c_str());
    usleep(1000000 / frames_per_second);
    system("clear");
  }

  // TODO: Clear videos, frames, and ascii folders
  std::cout
      << "Time to process frames to ASCII - using threads (microseconds): "
      << std::chrono::duration_cast<std::chrono::microseconds>(end - begin)
             .count()
      << '\n';
}
