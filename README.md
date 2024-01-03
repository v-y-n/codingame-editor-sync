# codingame-editor-sync

This repo contains 2 parts:  

- A **merger program**: Provides an HTTP route that merge all your code and return the result.
- A **firefox extension**: Call the merger's HTTP route and directly update your codingame's editor.   

Because of the way it works (for now), it **only works with C++ code, and only if you don't split implementation (.cpp) from definition (.h)**.  
Basically you want to use one `main.cpp` file that includes other `something.hpp` files.

### Build the Merger

Requires `gcc` and `make`

```sh
cd merger
make
```

### Load firefox extension

1. Write `about:debugging` in your firefox url bar.
2. Go in the "This Firefox" tab on the left
3. Click on "Load Temporary Add-On..." and select the `manifest.json` in the `extension` directory.

### Usage

1. Run the merger with `./codingame-editor-sync ./path/to/main.cpp`.
2. Ensure the firefox extension is loaded.
  
You should see red borders on the page and an update status above the codingame's editor (you might need to reload the page).
