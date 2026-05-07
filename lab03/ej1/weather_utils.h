/*
  @file weather_utils.h
  @brief defines weather table processing methods. These methods operates over multidimensional (year, month, day) array of weather
*/
#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include <stdio.h>
#include "weather_table.h"

/** 1) laboratorio (2a practico)
 * @brief searchs minimun weather on the whole table
 *
 * @param[in] Weather table
 * @return int value of the minimun temp registered
 */
int temp_min(WeatherTable a);


/** 2) (practico 2b)
 * @brief searchs max temperature of every year and stores it in array 'output'
 * @param[in] a table to get data from
 * @param output array
 */
void max_temp_array(WeatherTable a, int output[YEARS]);

/** 3) (practico 2c)
 * @brief searchs the month with the most amount of rainfalls of every year and stores it in array 'output'
 * @param[in] a table to get data from
 * @param output array
 */
void rainfall_month_array(WeatherTable a, month_t output[YEARS]);




#endif //_WEATHER_UTILS_H
