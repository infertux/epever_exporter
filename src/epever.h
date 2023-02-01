#include <inttypes.h>

enum {
  MAX_METRIC_LENGTH = 64,
};

typedef struct __attribute__((aligned(MAX_METRIC_LENGTH * 2))) {
  uint16_t address;
  char human_name[MAX_METRIC_LENGTH];
  char metric_name[MAX_METRIC_LENGTH];
  enum { REGISTER_SINGLE, REGISTER_DOUBLE } register_size;
  double scale;
} REGISTER;

const REGISTER holding_registers[] = {
    // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    /* 0x90xx - settings */
    {0x9004, "charging limit voltage", "settings_charging_limit_volts", REGISTER_SINGLE, 0.01},
    {0x9007, "boost charging voltage", "settings_boost_charging_volts", REGISTER_SINGLE, 0.01},
    {0x9008, "float charging voltage", "settings_float_charging_volts", REGISTER_SINGLE, 0.01},
    {0x9009, "boost reconnect voltage", "settings_boost_reconnect_volts", REGISTER_SINGLE, 0.01},
    {0x9065, "length of night", "settings_length_of_night_seconds", REGISTER_DOUBLE, 3600},
    {0x906C, "boost duration", "settings_boost_duration_seconds", REGISTER_SINGLE, 60},
    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
};

enum {
  REGISTER_CLOCK = 0x9013,
};

const REGISTER input_registers[] = {
    // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    /* 0x31XX - real time data */
    {0x3100, "PV voltage", "pv_volts", REGISTER_SINGLE, 0.01},
    {0x3101, "PV current", "pv_amps", REGISTER_SINGLE, 0.01},
    {0x3102, "PV power", "pv_watts", REGISTER_DOUBLE, 0.01},
    {0x3104, "battery voltage", "battery_volts", REGISTER_SINGLE, 0.01},
    {0x3105, "battery charging current", "battery_charging_amps", REGISTER_SINGLE, 0.01},
    {0x3106, "battery charging power", "battery_charging_watts", REGISTER_DOUBLE, 0.01},
    {0x310D, "battery discharging current", "battery_discharging_amps", REGISTER_SINGLE, 0.01},
    {0x310E, "battery discharging power", "battery_discharging_watts", REGISTER_DOUBLE, 0.01},
    {0x3110, "battery temperature", "temperature_battery_celsius", REGISTER_SINGLE, 0.01},
    {0x3111, "device temperature", "temperature_device_celsius", REGISTER_SINGLE, 0.01},
    {0x311A, "battery SOC", "battery_soc", REGISTER_SINGLE, 0.01},

    /* 0x32XX - status */
    {0x3200, "battery status", "battery_status", REGISTER_SINGLE, 1},
    {0x3201, "charging status", "charging_status", REGISTER_SINGLE, 1},

    /* 0x33XX - stats */
    {0x3302, "battery min voltage today", "battery_min_today_volts", REGISTER_SINGLE, 0.01},
    {0x3303, "battery max voltage today", "battery_max_today_volts", REGISTER_SINGLE, 0.01},
    {0x330C, "PV energy today", "energy_pv_today_kwh", REGISTER_DOUBLE, 0.01},
    {0x3312, "PV energy total", "energy_pv_total_kwh", REGISTER_DOUBLE, 0.01},
    // {0x311B, "battery net current (signed)", "battery_net_amps", REGISTER_DOUBLE, 0.01}, // XXX:
    // failing with "Illegal data address"
    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
};
