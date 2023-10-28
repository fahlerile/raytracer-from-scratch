#pragma once
#include <filesystem>
#include <limits>

// Error codes
constexpr int ERROR_CODE_SDL_INIT_FAIL = 1;
constexpr int ERROR_CODE_FILE_EXCEPTION = 2;
constexpr int ERROR_CODE_JSON_PARSE = 3;
constexpr int ERROR_CODE_JSON_FORMAT = 4;
constexpr int ERROR_CODE_JSON_UNKNOWN_TYPE = 5;
constexpr int ERROR_CODE_JSON_UNKNOWN_EXCEPTION = 6;

// Numeric constants
constexpr double qNaN = std::numeric_limits<double>::quiet_NaN();
constexpr double pi = 3.14159265358979323846;
constexpr double tolerance = 1e-5;  // used as a tolerance value to fix precision errors
                                    // if a value is greater than this tolerance, it is considered positive,
                                    // if a value is less than OR EQUAL TO this tolerance, it is considered zero/negative

// Other
constexpr int CAST_RAY_RECURSIVE_LIMIT = 3;
const std::filesystem::path scene_file_path = "scene.json";
