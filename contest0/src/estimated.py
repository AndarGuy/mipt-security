# Estimated time
# Сергей Сыроежкин и Электроник пытаются показать жителям города украденные бандой
# Стампа шедевры и разбудить город. Для этого они пытаются изменить установленное
# в часах время звона - вместо 1000000000 секунд Эпохи UNIX поставить 2006632960
# секунд эпохи UNIX. Напишите для Сыроежкина и Электроника программу-преобразователь,
# предполагая, что она работает на little-endian машинах.

pattern, payload = [0x00, 0xca, 0x9a, 0x3b], [0x00, 0xca, 0x9a, 0x77]
pattern, payload = bytes(pattern), bytes(payload)
source = bytearray(open("source", "rb").read())
source = source.replace(pattern, payload)
open("cracked", "wb").write(source)
