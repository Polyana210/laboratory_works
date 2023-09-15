import { createSlice } from "@reduxjs/toolkit";

export const tasksSlice = createSlice({
    name: "tasks",
    info: "task",
    initialState: [
      {id: 0, req: false, name: 'Витебский государственный университет', info: 'Научно-образовательный центр Белоруссии, одно из старейших высших учебных заведений страны. ', specialities : ['dcd', 'dcsdcsdc', 'cdcdscsdcsd']},
      {id: 1, req: false, name: 'Витебский государственный технологический университет',  info: 'Высшее учебное заведение в Витебске. В состав университета входят 7 факультетов, 17 кафедр. Имеется 5 учебных корпусов, 2 общежития, экспериментально-опытное предприятие, аспирантура, библиотека, спортивно-оздоровительный комплекс.'},
      {id: 2, req: true ,name: 'Витебский государственный медицинский hygv gftf hgyftgv университет',  info:'Высшее медицинское учебное заведение в городе Витебске, Республика Беларусь.'},
    ],
    
    reducers:{
        addEstablishment: (state, action)=>{
            const newEstablishment = {
                id: nextId++,
                name: action.payload.name,
                info: action.payload.info,
                specialities: [],
                req: true
            }
            state.push(newEstablishment);
        },
        deletePost: (state, action)=>{
            return state.filter((item) => item.id !== action.payload.id);
        },
        agreePost: (state, action)=>{
        }
        
    }
});

export const {addEstablishment, deletePost, agreePost} = tasksSlice.actions;
let nextId = 3;
export default tasksSlice.reducer;