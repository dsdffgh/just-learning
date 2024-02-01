/*
 * =====================================================================================
 *
 *       Filename:  calculatingPI_to15000_digits.c
 *
 *    Description:  Calculating Pi in 2 lines by Dik T. Winter
 *
 *        Version:  1.0
 *        Created:  11/16/23 19:45:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonesssssssss (), whyunotdo@qq.com
 *   Organization:
 *
 * =====================================================================================
 */

a[52514], b, c = 52514, d, e, f = 1e4, g, h;
main() {
  for (; b = c -= 14; h = printf("%04d", e + d / f))
    for (e = d %= f; g = --b * 2; d /= g)
      d = d * b + f * (h ? a[b] : f / 5), a[b] = d % --g;
}
