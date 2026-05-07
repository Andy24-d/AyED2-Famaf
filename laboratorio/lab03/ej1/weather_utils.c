/*
  @file weather.c
  @brief Implements weather data analisys
*/
#include <stdlib.h>
#include "weather_table.h"
#include "weather_utils.h"


int temp_min(WeatherTable a)
{
    int min = a[0][0][0]._min_temp;
    int temp_aux;
    
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
            
                temp_aux = a[year][month][day]._min_temp;
                //Si se encuentra un valor menor, se actualiza 'min'
                if( min > temp_aux ) min = temp_aux;
            }
        }
    }

  return min;
}

void max_temp_array(WeatherTable a, int output[YEARS])
{
    int max = a[0][0][0]._max_temp;
    int temp_aux;
    
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
            
                temp_aux = a[year][month][day]._max_temp;
                //Si se encuentra un valor menor, se actualiza 'min'
                if( max < temp_aux ) max = temp_aux;
            }
        }
        
        output[year] = max;
        max = a[year][0][0]._max_temp;
    }
}

static unsigned int rainfall_om(WeatherTable a, int year, month_t month)
{
    unsigned int rain_count = 0;
    for(unsigned int day = 0; day < DAYS ; ++day){
        rain_count += a[year][month][day]._rainfall;
    }
    
    return rain_count;
}

void rainfall_month_array(WeatherTable a, month_t output[YEARS])
{
    unsigned int amount = 0;
    unsigned int max_amount = 0;
    month_t max_rain_month = january;
    
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
        
            amount = rainfall_om(a, year, month);
            
            if (amount > max_amount){
                max_amount = amount;
                max_rain_month = month;
            }
        }
        
        output[year] = max_rain_month;
        
        //Reset de variables
        max_amount = 0;
        max_rain_month = january;
    }
}


