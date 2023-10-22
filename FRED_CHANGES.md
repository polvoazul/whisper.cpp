## What i changed

* Finding a way to get scores per token
  new_segment_callback in js

* A way to interrupt calculations
  encoder_begin_callback returning false aborts
  set it via js on emscripten.cpp




https://github.com/ggerganov/whisper.cpp/issues/1366


--- 

Things to look at:
encode time is too slow in emscripten

EMSCRIPTEN:
load time =   160.42 ms
fallbacks =   2 p /   0 h
mel time =  1622.11 ms
sample time =   816.96 ms /   554 runs (    1.47 ms per run)
encode time = 54808.84 ms /     8 runs ( 6851.10 ms per run)
decode time =  5425.68 ms /   542 runs (   10.01 ms per run)
prompt time =  7499.45 ms /    10 runs (  749.94 ms per run)
total time = 71294.85 ms


CPP MAIN:
load time =   438.31 ms
fallbacks =   1 p /   0 h
mel time =   110.10 ms
sample time =   334.48 ms /   551 runs (    0.61 ms per run)
encode time =  2010.17 ms /     9 runs (  223.35 ms per run)
decode time =  3305.52 ms /   540 runs (    6.12 ms per run)
prompt time =   313.38 ms /    10 runs (   31.34 ms per run)
total time =  6686.80 ms
