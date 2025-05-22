import { View, Text, FlatList, TouchableOpacity, Image, StyleSheet } from 'react-native'
import React, { useEffect, useState } from 'react'
import Colors from './../../constant/Colors'
import {db} from './../../config/firebaseConfig'
import {collection, query, where} from 'firebase/firestore'
import { imageAssets } from '../constant/Option'
import { Ionicons } from '@expo/vector-icons'


export default function CourseListByCategory({category}){
    
    const [courseList, setCourseList] = useState([]);
    const [loading, setLoading] = useState(false);
    useEffect(() => {
        GetCourseListByCategory();
    }, [])
    
    const GetCourseListByCategory = async () => {
        setCourseList([]);
        setLoading(true);
        const q = query(collection(db, 'Courses'),
            where('category', '==', category),
            orderBy('createdOn', 'desc'))
            
            const querySnapshot = await getDocs(q);

            querySnapshot?.forEach((doc) => {
                console.log("--", doc.data());
                setCourseList(prev => [...prev, doc.data()])
            })
        setLoading(false);
    }
    
    return (
        <View>
          {courseList?.length > 0 && <CourseList courseList = {courseList} heading = {category}/>}
            enroll = {true}
        </View>
    )
}

const styles = StyleSheet.create({
    courseContainer:{
        padding: 10,
        background: Colors.BG_GRAY,
        margin: 6,
        boderRadius: 15,
        width: 260
    }
})