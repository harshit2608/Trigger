#pragma once

namespace Trigger
{
    int64_t lasttermap(double a, int64_t n, double d)
    {
        return (a + (n - 1) * d);
    }
    double sumofap(double a, int64_t n, double d)
    {
        return ((n / 2) * (lasttermap(a, n, d) + a));
    }

    int64_t numofterms(double a, double l, double d)
    {
        return (((l - a) / d) + 1);
    }

    int64_t lasttermgp(double a, int64_t n, double d)
    {
        return (a + (n - 1) * d);
    }

    double sumofgp(double a, int64_t n, double d)
    {
        return ((n / 2) * (lasttermgp(a, n, d) + a));
    }
} // namespace Trigger