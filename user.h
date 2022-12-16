/*
 * user.h
 *
 *  Created on: 16 dec. 2022
 *      Author: awaal
 */

#ifndef USER_H_
#define USER_H_

// time zone and daylight savings settings
#define CLOCK_DST_RULE                                                         \
  { "EDT", Last, Sun, Mar, 3, 120 } // UTC + 2 hours in summer
#define CLOCK_STD_RULE                                                         \
  { "EST", Last, Sun, Oct, 2, 60 } // UTC + 1 hour in winter



#endif /* USER_H_ */
