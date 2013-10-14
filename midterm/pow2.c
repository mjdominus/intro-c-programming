long int pow2(int n, int p)
{
  /* Has value n^(2^i) the i'th time through the loop */
  long int np = n;

  long int answer = 1;
  
  while (p) {
    if (p%2)
      answer *= np;
    p = p/2;
    np *= np;			/* np had n^(2^i), now has n^(2^(i+1)). */
  }
    
  return answer;
}
