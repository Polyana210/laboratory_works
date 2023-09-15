import React, { StrictMode } from "react";
import { createRoot } from "react-dom/client";
import "./styles.css";
import { BrowserRouter } from 'react-router-dom';

import AppComponent from "./AppComponent";

const root = createRoot(document.getElementById("root"));
root.render(
<BrowserRouter>
    <AppComponent />
  </BrowserRouter>
);

