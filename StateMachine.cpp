enum MyStates 
{
  IDLE_STATE,
  MEASURING_DATA,
  REPORTING_DATA,
  WAITING_FOR_RESPONSE,
};

MyStates mainState = IDLE_STATE;

void setup() 
{
  // put your setup code here, to run once:
}

void loop() 
{
  static MyStates lastState = mainState;

  // react to state changes...
  //
  if (mainState != lastState) 
  {
    switch (mainState) 
	{
      case IDLE_STATE:
        // perform functions to return to IDLE_STATE
        break;
      case MEASURING_DATA:
        // perform functions to return to STATE_ONE
        break;
      case REPORTING_DATA:
        // perform functions to return to STATE_TWO
        break;
      case WAITING_FOR_RESPONSE:
        // perform functions to return to STATE_THREE
        break;
      default:
        //
        break;
    }
    lastState = mainState;
  }

  // manage states...
  //
  switch (mainState) 
  {
    case IDLE_STATE:
      idleState();
      break;
    case MEASURING_DATA:
      measuringData();
      break;
    case REPORTING_DATA:
      reporingData();
      break;
    case WAITING_FOR_RESPONSE:
      waitingForResponse();
      break;
  }
}

void idleState() 
{
  // some non-blocking set of function calls in these functions... for example
}

void measuringData() 
{
  
}

void reporingData() 
{
  
}

void waitingForResponse() 
{
  
}
