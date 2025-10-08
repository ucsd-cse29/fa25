int8_t is_ascii_bitand(char c) {
  return (c & 0x10000000) == 0;
}
