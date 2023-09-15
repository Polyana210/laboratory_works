import React, { StrictMode } from "react";
import { createRoot } from "react-dom/client";
import "./styles.css";

import AppComponent from "./AppComponent";

const root = createRoot(document.getElementById("root"));
root.render(
  <StrictMode>
    <AppComponent />
  </StrictMode>
);