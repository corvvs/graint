# 角速度

ds = `dd`
  .split("\n")
  .compact
  .reject{ |s| s.match?(/^\s*$/) || s.match?(/^\s*#/) }
  .map{ |s|
    s.split.map &:to_f
  }
  .map{ |rs|
    [
      [rs[0] - rs[2], rs[1] - rs[3]],
      [rs[2] - rs[4], rs[3] - rs[5]],
      [rs[4] - rs[0], rs[5] - rs[1]],
    ]
  }
  .map{ |ds|
    dd12 = Math.sqrt(ds[0][0] ** 2 + ds[0][1] ** 2)
    dd23 = Math.sqrt(ds[1][0] ** 2 + ds[1][1] ** 2)
    dd31 = Math.sqrt(ds[2][0] ** 2 + ds[2][1] ** 2)
    [
      [ds[0][0] / dd12, ds[0][1] / dd12],
      [ds[1][0] / dd23, ds[1][1] / dd23],
      [ds[2][0] / dd31, ds[2][1] / dd31],
    ]
  }

DT = 0.001

dphis = (1...ds.size).map{ |i|
  ra = ds[i - 1]
  rb = ds[i]
  [
    ra[0][0] * rb[0][1] - ra[0][1] * rb[0][0],
    ra[1][0] * rb[1][1] - ra[1][1] * rb[1][0],
    ra[2][0] * rb[2][1] - ra[2][1] * rb[2][0],
  ]
}.map{ |dphis|
  dphis.map{ |dp| dp / DT }
}

p dphis.map{ |dps| dps[0] }.sum / dphis.size