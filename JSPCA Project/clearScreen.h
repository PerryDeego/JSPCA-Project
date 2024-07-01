//
//  clearScreen.h
//  JSPCA Project
//
//  Created by Perry  on 14/03/2023.
//

#ifndef clearScreen_h
#define clearScreen_h

#include <unistd.h>
#include <term.h>

void clearScreen()
{
  if (!cur_term)
    {
    int result;
    setupterm( NULL, STDOUT_FILENO, &result );
    if (result <= 0) return;
    }

  putp( tigetstr( "clear" ) );
}

#endif /* clearScreen_h */
