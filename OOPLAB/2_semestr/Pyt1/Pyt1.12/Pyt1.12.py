#12
#Напишите генератор get_frames(), который производит «оконную декомпозицию» сигнала: на основе входного списка генерирует набор
#списков – перекрывающихся отдельных фрагментов сигнала размера size со степенью перекрытия overlap.

def get_frames(signal, size, overlap):
    step = int(size * overlap)
    stop = len(signal) - 1
    for start in range(0, stop, step):
        yield [i for i in signal[start : start + size] ]

[print(frame) for frame in get_frames(range(10),2,0.5)]
