import { configureStore } from "@reduxjs/toolkit";
import taskReducer from "./postsSlice";

export default configureStore({
    reducer:{
        tasks: taskReducer,
    }
});