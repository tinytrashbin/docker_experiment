#include <chrono>

inline int64_t GetEpochMicroSeconds() {
  using namespace std::chrono;  // NOLINT
  return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
}

class MicroSecondTimer {
 public:
  MicroSecondTimer() {this->Restart();}
  void Restart() {
    paused_at = 0;
    pause_duration = 0;
    start_time = GetEpochMicroSeconds();
  }
  void Pause() {
    if (paused_at == 0) {
      paused_at = GetEpochMicroSeconds();
    }
  }
  void Resume() {
    if (paused_at != 0) {
      pause_duration += GetEpochMicroSeconds() - paused_at;
      paused_at = 0;
    }
  }
  int64_t GetStartTime() const {
    return start_time;
  }
  int64_t GetElapsedTime() const {
    return GetEpochMicroSeconds() - start_time - pause_duration;
  }
 private:
  int64_t start_time;
  int64_t paused_at;
  int64_t pause_duration;
};

