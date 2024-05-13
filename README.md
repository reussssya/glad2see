# glad2see - no more Spotify needed
## Dependencies
- CMake & Conan 
- Inter Black (900) Font 


**Step 1: Install dependencies with Conan**
- libmysqlclient 
- spdlog
- Qt
```bash
conan install . --output-folder=build --build=missing
conan build . --output-folder=./build
```

**Step 2: Run CMake build**
```bash
cmake --build ./build --parallel 6 --config Release
```

**Step 3: Create database (mysql 8)**
You can use for localhost Denwer or OSPanel (both includes phpmyadmin, easy to manage db)
- Create database named 'glad2see'
- Import in phpmyadmin glad2see_full.sql