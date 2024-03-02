# file_path = r"C:\Users\Student\Downloads\output.wav"
file_path = r"Test-001.wav"

# Step 1: Open the WAV file
with open(file_path, "rb") as wav_file:
    # Step 2: Read frame data
    # frames = wav_file.readframes(wav_file.getnframes())
    
    # Step 3: Convert to hex
    # hex_values = binascii.hexlify(frames)
    hex_values = wav_file.read().hex()
    
     # Separate each hex number and put them into a list
    hex_list = ["0x"+hex_values[i:i+2] for i in range(0, len(hex_values), 2)]

with open("output.txt", "w") as file:
    file.write(", ".join(hex_list))